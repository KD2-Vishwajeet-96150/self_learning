const express = require("express");

const courseRoutes = require("./routes/courseRoutes");
const studentRoutes = require("./routes/studentRoutes");

const app = express();

app.use(express.json());

app.use("/courses", courseRoutes);
app.use("/students", studentRoutes);

app.listen(5000, () => {
  console.log("Server running on port 5000");
});