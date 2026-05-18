const express = require("express");
const db = require("../db");

const router = express.Router();

// GET
router.get("/", (req, res) => {
  db.query("SELECT * FROM courses", (err, result) => {
    res.json(result);
  });
});

// POST
router.post("/", (req, res) => {

  const { name, fees } = req.body;

  db.query(
    "INSERT INTO courses(name, fees) VALUES(?, ?)",
    [name, fees],
    (err, result) => {
      res.json({
        message: "Course Added"
      });
    }
  );
});

// PUT
router.put("/:id", (req, res) => {

  const { name, fees } = req.body;

  db.query(
    "UPDATE courses SET name=?, fees=? WHERE id=?",
    [name, fees, req.params.id],
    (err, result) => {
      res.json({
        message: "Course Updated"
      });
    }
  );
});

// DELETE
router.delete("/:id", (req, res) => {

  db.query(
    "DELETE FROM courses WHERE id=?",
    [req.params.id],
    (err, result) => {
      res.json({
        message: "Course Deleted"
      });
    }
  );
});

module.exports = router;