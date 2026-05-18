const http = require("http");

let products = [
  { id: 1, name: "Laptop", price: 50000 },
  { id: 2, name: "Phone", price: 20000 }
];

const server = http.createServer((req, res) => {

  res.setHeader("Content-Type", "application/json");

  // GET ALL PRODUCTS
  if (req.method === "GET" && req.url === "/products") {
    res.end(JSON.stringify(products));
  }

  // ADD PRODUCT
  else if (req.method === "POST" && req.url === "/products") {

    let body = "";

    req.on("data", chunk => {
      body += chunk.toString();
    });

    req.on("end", () => {
      const product = JSON.parse(body);

      products.push(product);

      res.end(JSON.stringify({
        message: "Product Added",
        products
      }));
    });
  }

  // UPDATE PRODUCT
  else if (req.method === "PUT" && req.url.startsWith("/products/")) {

    const id = parseInt(req.url.split("/")[2]);

    let body = "";

    req.on("data", chunk => {
      body += chunk.toString();
    });

    req.on("end", () => {

      const updatedProduct = JSON.parse(body);

      products = products.map(product =>
        product.id === id ? updatedProduct : product
      );

      res.end(JSON.stringify({
        message: "Product Updated",
        products
      }));
    });
  }

  // DELETE PRODUCT
  else if (req.method === "DELETE" && req.url.startsWith("/products/")) {

    const id = parseInt(req.url.split("/")[2]);

    products = products.filter(product => product.id !== id);

    res.end(JSON.stringify({
      message: "Product Deleted",
      products
    }));
  }

  else {
    res.statusCode = 404;

    res.end(JSON.stringify({
      message: "Route Not Found"
    }));
  }
});

server.listen(4000, () => {
  console.log("Server running on port 4000");
});