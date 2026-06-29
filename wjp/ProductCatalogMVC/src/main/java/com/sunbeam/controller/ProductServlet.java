package com.sunbeam.controller;

import com.sunbeam.dao.ProductDao;
import com.sunbeam.entities.Product;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.*;

import java.io.IOException;
import java.util.List;

@WebServlet("/products")
public class ProductServlet extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest request,
                          HttpServletResponse response)
            throws ServletException, IOException {

        long categoryId =
                Long.parseLong(request.getParameter("categoryId"));

        ProductDao dao = new ProductDao();

        List<Product> products =
                dao.getProductsByCategory(categoryId);

        request.setAttribute("products", products);

        request.getRequestDispatcher("/WEB-INF/views/products.jsp")
                .forward(request, response);
    }

    @Override
    protected void doGet(HttpServletRequest request,
                         HttpServletResponse response)
            throws ServletException, IOException {

        doPost(request, response);
    }
}