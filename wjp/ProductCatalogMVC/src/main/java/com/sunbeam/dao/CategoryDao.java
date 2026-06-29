package com.sunbeam.dao;

import com.sunbeam.entities.Category;
import com.sunbeam.utils.DbUtil;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class CategoryDao {

    public List<Category> getAllCategories() {

        List<Category> list = new ArrayList<>();

        String sql = "select * from categories";

        try (
                Connection con = DbUtil.getConnection();
                PreparedStatement stmt = con.prepareStatement(sql);
                ResultSet rs = stmt.executeQuery();
        ) {

            while (rs.next()) {

                Category c = new Category();

                c.setCategoryId(rs.getLong("category_id"));
                c.setCategoryName(rs.getString("category_name"));
                c.setDescription(rs.getString("description"));

                list.add(c);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }

        return list;
    }

}