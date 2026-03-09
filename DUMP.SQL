-- MySQL dump 10.13  Distrib 9.6.0, for Win64 (x86_64)
--
-- Host: localhost    Database: cdac_center_allocation
-- ------------------------------------------------------
-- Server version	9.6.0

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
SET @MYSQLDUMP_TEMP_LOG_BIN = @@SESSION.SQL_LOG_BIN;
SET @@SESSION.SQL_LOG_BIN= 0;

--
-- GTID state at the beginning of the backup 
--

SET @@GLOBAL.GTID_PURGED=/*!80000 '+'*/ '964ffc99-1234-11f1-897c-00ff982f0a8f:1-228';

--
-- Table structure for table `allocation`
--

DROP TABLE IF EXISTS `allocation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `allocation` (
  `form_no` int NOT NULL,
  `course_id` int DEFAULT NULL,
  `center_id` int DEFAULT NULL,
  PRIMARY KEY (`form_no`),
  KEY `course_id` (`course_id`),
  KEY `center_id` (`center_id`),
  CONSTRAINT `allocation_ibfk_1` FOREIGN KEY (`form_no`) REFERENCES `candidates` (`form_no`),
  CONSTRAINT `allocation_ibfk_2` FOREIGN KEY (`course_id`) REFERENCES `courses` (`course_id`),
  CONSTRAINT `allocation_ibfk_3` FOREIGN KEY (`center_id`) REFERENCES `centers` (`center_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `allocation`
--

LOCK TABLES `allocation` WRITE;
/*!40000 ALTER TABLE `allocation` DISABLE KEYS */;
INSERT INTO `allocation` VALUES (101,1,1),(102,1,2),(103,2,1),(104,1,1),(105,2,2),(106,1,2),(107,2,1),(108,1,1),(109,2,2);
/*!40000 ALTER TABLE `allocation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `candidates`
--

DROP TABLE IF EXISTS `candidates`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `candidates` (
  `form_no` int NOT NULL,
  `name` varchar(50) DEFAULT NULL,
  `candidate_rank` int DEFAULT NULL,
  PRIMARY KEY (`form_no`),
  UNIQUE KEY `candidate_rank` (`candidate_rank`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `candidates`
--

LOCK TABLES `candidates` WRITE;
/*!40000 ALTER TABLE `candidates` DISABLE KEYS */;
INSERT INTO `candidates` VALUES (101,'Amit',1),(102,'Neha',2),(103,'Rahul',3),(104,'Priya',4),(105,'Karan',5),(106,'Sneha',6),(107,'Vikas',7),(108,'Anjali',8),(109,'Rohit',9);
/*!40000 ALTER TABLE `candidates` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `centers`
--

DROP TABLE IF EXISTS `centers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `centers` (
  `center_id` int NOT NULL,
  `center_name` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`center_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `centers`
--

LOCK TABLES `centers` WRITE;
/*!40000 ALTER TABLE `centers` DISABLE KEYS */;
INSERT INTO `centers` VALUES (1,'sunbeam'),(2,'CDAC Pune'),(3,'CDAC Bangalore');
/*!40000 ALTER TABLE `centers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `courses`
--

DROP TABLE IF EXISTS `courses`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `courses` (
  `course_id` int NOT NULL,
  `course_name` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`course_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `courses`
--

LOCK TABLES `courses` WRITE;
/*!40000 ALTER TABLE `courses` DISABLE KEYS */;
INSERT INTO `courses` VALUES (1,'PGCP-AC'),(2,'PGCP-MC'),(3,'PGCP-AI');
/*!40000 ALTER TABLE `courses` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `preferences`
--

DROP TABLE IF EXISTS `preferences`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `preferences` (
  `form_no` int NOT NULL,
  `pref_no` int NOT NULL,
  `course_id` int DEFAULT NULL,
  `center_id` int DEFAULT NULL,
  PRIMARY KEY (`form_no`,`pref_no`),
  KEY `course_id` (`course_id`),
  KEY `center_id` (`center_id`),
  CONSTRAINT `preferences_ibfk_1` FOREIGN KEY (`form_no`) REFERENCES `candidates` (`form_no`),
  CONSTRAINT `preferences_ibfk_2` FOREIGN KEY (`course_id`) REFERENCES `courses` (`course_id`),
  CONSTRAINT `preferences_ibfk_3` FOREIGN KEY (`center_id`) REFERENCES `centers` (`center_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `preferences`
--

LOCK TABLES `preferences` WRITE;
/*!40000 ALTER TABLE `preferences` DISABLE KEYS */;
INSERT INTO `preferences` VALUES (101,1,1,1),(101,2,2,1),(102,1,1,2),(102,2,2,1),(103,1,2,1),(103,2,1,1),(104,1,1,1),(104,2,2,2),(105,1,2,2),(105,2,1,1),(106,1,1,2),(106,2,2,2),(107,1,2,1),(107,2,1,2),(108,1,1,1),(108,2,2,1),(109,1,2,2),(109,2,1,2);
/*!40000 ALTER TABLE `preferences` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `seat_matrix`
--

DROP TABLE IF EXISTS `seat_matrix`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `seat_matrix` (
  `course_id` int NOT NULL,
  `center_id` int NOT NULL,
  `total_seats` int DEFAULT NULL,
  `remaining_seats` int DEFAULT NULL,
  PRIMARY KEY (`course_id`,`center_id`),
  KEY `center_id` (`center_id`),
  CONSTRAINT `seat_matrix_ibfk_1` FOREIGN KEY (`course_id`) REFERENCES `courses` (`course_id`),
  CONSTRAINT `seat_matrix_ibfk_2` FOREIGN KEY (`center_id`) REFERENCES `centers` (`center_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `seat_matrix`
--

LOCK TABLES `seat_matrix` WRITE;
/*!40000 ALTER TABLE `seat_matrix` DISABLE KEYS */;
INSERT INTO `seat_matrix` VALUES (1,1,3,0),(1,2,3,1),(1,3,3,3),(2,1,3,1),(2,2,3,1),(2,3,3,3),(3,1,3,3),(3,2,3,3),(3,3,3,3);
/*!40000 ALTER TABLE `seat_matrix` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'cdac_center_allocation'
--
/*!50003 DROP PROCEDURE IF EXISTS `add_preference` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = cp850 */ ;
/*!50003 SET character_set_results = cp850 */ ;
/*!50003 SET collation_connection  = cp850_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`KD2-Vishwajeet-96150`@`localhost` PROCEDURE `add_preference`(
    IN p_form_no INT,
    IN p_pref_no INT,
    IN p_course_id INT,
    IN p_center_id INT
)
BEGIN

INSERT INTO preferences(form_no, pref_no, course_id, center_id)
VALUES(p_form_no, p_pref_no, p_course_id, p_center_id);

END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `allocate_seats` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = cp850 */ ;
/*!50003 SET character_set_results = cp850 */ ;
/*!50003 SET collation_connection  = cp850_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`KD2-Vishwajeet-96150`@`localhost` PROCEDURE `allocate_seats`()
BEGIN

DECLARE done INT DEFAULT 0;
DECLARE pref_done INT DEFAULT 0;

DECLARE v_form INT;
DECLARE v_course INT;
DECLARE v_center INT;

-- Cursor for candidates in rank order
DECLARE cur_candidates CURSOR FOR
SELECT form_no
FROM candidates
ORDER BY candidate_rank;

-- Handler for candidate cursor
DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

OPEN cur_candidates;

candidate_loop: LOOP

FETCH cur_candidates INTO v_form;

IF done = 1 THEN
LEAVE candidate_loop;
END IF;

SET pref_done = 0;

-- Cursor for preferences of current candidate
BEGIN

DECLARE cur_pref CURSOR FOR
SELECT course_id, center_id
FROM preferences
WHERE form_no = v_form
ORDER BY pref_no;

DECLARE CONTINUE HANDLER FOR NOT FOUND SET pref_done = 1;

OPEN cur_pref;

pref_loop: LOOP

FETCH cur_pref INTO v_course, v_center;

IF pref_done = 1 THEN
LEAVE pref_loop;
END IF;

-- Check seat availability
IF (SELECT remaining_seats
    FROM seat_matrix
    WHERE course_id = v_course
    AND center_id = v_center) > 0 THEN

INSERT INTO allocation(form_no, course_id, center_id)
VALUES(v_form, v_course, v_center);

-- Reduce seat count
UPDATE seat_matrix
SET remaining_seats = remaining_seats - 1
WHERE course_id = v_course
AND center_id = v_center;

LEAVE pref_loop;

END IF;

END LOOP;

CLOSE cur_pref;

END;

END LOOP;

CLOSE cur_candidates;

END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
SET @@SESSION.SQL_LOG_BIN = @MYSQLDUMP_TEMP_LOG_BIN;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2026-03-09  0:03:53
