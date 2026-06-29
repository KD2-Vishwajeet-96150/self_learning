<%@ page contentType="text/html;charset=UTF-8" language="java"%>
<%@ taglib prefix="c" uri="jakarta.tags.core"%>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Products</title>
</head>

<body>
<h2>Products</h2>
<c:choose>
    <c:when test="${empty products}">
        <h3>No products found for this category.</h3>
    </c:when>
    <c:otherwise>
        <table border="1" cellpadding="10">
            <tr>
                <th>Product Name</th> 
                <th>Price</th>
                <th>Stock</th>
            </tr>
            <c:forEach items="${products}" var="p">
                <tr>
                    <td>${p.productName}</td>

                    <td>${p.price}</td>

                    <td>${p.stock}</td>

                </tr>

            </c:forEach>

        </table>

    </c:otherwise>

</c:choose>

<br>

<a href="home">Back</a>

</body>
</html>