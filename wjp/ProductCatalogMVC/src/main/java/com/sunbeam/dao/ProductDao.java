package com.sunbeam.dao;

import com.sunbeam.entities.Product;
import com.sunbeam.utils.DbUtil;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class ProductDao {

    public List<Product> getProductsByCategory(long categoryId) {

        List<Product> list = new ArrayList<>();

        String sql = "select * from products where category_id=?";

        try (
                Connection con = DbUtil.getConnection();
                PreparedStatement stmt = con.prepareStatement(sql);
        ) {

            stmt.setLong(1, categoryId);

            ResultSet rs = stmt.executeQuery();

            while (rs.next()) {

                Product p = new Product();

                p.setProductId(rs.getLong("product_id"));
                p.setProductName(rs.getString("product_name"));
                p.setPrice(rs.getDouble("price"));
                p.setStock(rs.getInt("stock"));
                p.setCategoryId(rs.getLong("category_id"));

                list.add(p);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }

        return list;
    }

}