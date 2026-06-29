<%@ page contentType="text/html;charset=UTF-8" language="java"%>
<%@ taglib prefix="c" uri="jakarta.tags.core"%>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Product Catalog</title>
</head>

<body>
<h2>Select Category</h2>
<form action="products" method="post">

    <select name="categoryId">

        <c:forEach items="${categories}" var="c">

            <option value="${c.categoryId}">
                ${c.categoryName}
            </option>

        </c:forEach>

    </select>

    <br><br>

    <input type="submit" value="Show Products">

</form>

</body>
</html>