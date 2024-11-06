-- MySQL dump 10.13  Distrib 8.0.35, for Linux (x86_64)
--
-- Host: localhost    Database: Armor
-- ------------------------------------------------------
-- Server version	8.0.35-0ubuntu0.22.04.1

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

--
-- Table structure for table `Boots`
--

DROP TABLE IF EXISTS `Boots`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Boots` (
  `Name` varchar(20) DEFAULT NULL,
  `Points` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Boots`
--

LOCK TABLES `Boots` WRITE;
/*!40000 ALTER TABLE `Boots` DISABLE KEYS */;
INSERT INTO `Boots` VALUES ('Health',4),('Attack',6),('Defence',5),('Speed',15);
/*!40000 ALTER TABLE `Boots` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Equipment`
--

DROP TABLE IF EXISTS `Equipment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Equipment` (
  `ID` int DEFAULT NULL,
  `TYPEOFARMOR` varchar(20) DEFAULT NULL,
  `Health` int DEFAULT NULL,
  `Attack` int DEFAULT NULL,
  `Defence` int DEFAULT NULL,
  `Speed` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Equipment`
--

LOCK TABLES `Equipment` WRITE;
/*!40000 ALTER TABLE `Equipment` DISABLE KEYS */;
INSERT INTO `Equipment` VALUES (1,'Helmet',10,0,10,2),(2,'Vest',12,0,15,1),(3,'Gloves',9,7,9,3),(4,'Boots',11,6,8,5);
/*!40000 ALTER TABLE `Equipment` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Gloves`
--

DROP TABLE IF EXISTS `Gloves`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Gloves` (
  `Name` varchar(20) DEFAULT NULL,
  `Points` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Gloves`
--

LOCK TABLES `Gloves` WRITE;
/*!40000 ALTER TABLE `Gloves` DISABLE KEYS */;
INSERT INTO `Gloves` VALUES ('Health',7),('Attack',10),('Defence',7),('Speed',5);
/*!40000 ALTER TABLE `Gloves` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Helmet`
--

DROP TABLE IF EXISTS `Helmet`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Helmet` (
  `Name` varchar(50) DEFAULT NULL,
  `Point` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Helmet`
--

LOCK TABLES `Helmet` WRITE;
/*!40000 ALTER TABLE `Helmet` DISABLE KEYS */;
INSERT INTO `Helmet` VALUES ('Health',5),('attack',0),('defence',10),('speed',10);
/*!40000 ALTER TABLE `Helmet` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Vest`
--

DROP TABLE IF EXISTS `Vest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Vest` (
  `Name` varchar(20) DEFAULT NULL,
  `Points` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Vest`
--

LOCK TABLES `Vest` WRITE;
/*!40000 ALTER TABLE `Vest` DISABLE KEYS */;
INSERT INTO `Vest` VALUES ('Health',20),('Attack',0),('Defence',15),('Speed',7);
/*!40000 ALTER TABLE `Vest` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-11-10 11:38:34
