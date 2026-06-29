package com.sunbeam.controller;

import com.sunbeam.dao.CategoryDao;
import com.sunbeam.entities.Category;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.*;

import java.io.IOException;
import java.util.List;

@WebServlet("/home")
public class HomeServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request,
                         HttpServletResponse response)
            throws ServletException, IOException {

        CategoryDao dao = new CategoryDao();

        List<Category> categories = dao.getAllCategories();

        request.setAttribute("categories", categories);

        request.getRequestDispatcher("/WEB-INF/views/home.jsp")
                .forward(request, response);
    }
}