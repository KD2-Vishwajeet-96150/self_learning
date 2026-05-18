const express = require("express");
const db = require("../db");

const router = express.Router();

// GET
router.get("/", (req, res) => {
  db.query("SELECT * FROM students", (err, result) => {
    res.json(result);
  });
});

// POST
router.post("/", (req, res) => {

  const { name, age } = req.body;

  db.query(
    "INSERT INTO students(name, age) VALUES(?, ?)",
    [name, age],
    (err, result) => {
      res.json({
        message: "Student Added"
      });
    }
  );
});

// PUT
router.put("/:id", (req, res) => {

  const { name, age } = req.body;

  db.query(
    "UPDATE students SET name=?, age=? WHERE id=?",
    [name, age, req.params.id],
    (err, result) => {
      res.json({
        message: "Student Updated"
      });
    }
  );
});

// DELETE
router.delete("/:id", (req, res) => {

  db.query(
    "DELETE FROM students WHERE id=?",
    [req.params.id],
    (err, result) => {
      res.json({
        message: "Student Deleted"
      });
    }
  );
});

module.exports = router;