-- MySQL dump 10.13  Distrib 5.7.35, for Linux (x86_64)
--
-- Host: 127.0.0.1    Database: pytest
-- ------------------------------------------------------
-- Server version	5.7.34-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `account_pixels`
--

DROP TABLE IF EXISTS `account_pixels`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `account_pixels` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `account_id` int(10) unsigned NOT NULL,
  `alias` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  `status` enum('active','deleted') NOT NULL DEFAULT 'active',
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account_pixels`
--

LOCK TABLES `account_pixels` WRITE;
/*!40000 ALTER TABLE `account_pixels` DISABLE KEYS */;
/*!40000 ALTER TABLE `account_pixels` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `accounts`
--

DROP TABLE IF EXISTS `accounts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `accounts` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `materialized_path` varchar(3000) NOT NULL,
  `parent_id` int(10) unsigned DEFAULT NULL,
  `currency_id` int(10) unsigned DEFAULT NULL,
  `name` varchar(255) NOT NULL,
  `restrictions` varchar(3000) DEFAULT NULL,
  `cpm` bigint(20) unsigned NOT NULL DEFAULT '0',
  `limit_bid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `status` enum('active','blocked','deleted') NOT NULL DEFAULT 'active',
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `accounts`
--

LOCK TABLES `accounts` WRITE;
/*!40000 ALTER TABLE `accounts` DISABLE KEYS */;
INSERT INTO `accounts` VALUES (1,'/2/2',NULL,1,'admin',NULL,0,0,'active','2019-06-17 11:46:06','2021-09-28 19:40:12');
/*!40000 ALTER TABLE `accounts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `bankers`
--

DROP TABLE IF EXISTS `bankers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bankers` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `dc_id` int(10) unsigned NOT NULL,
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bankers`
--

LOCK TABLES `bankers` WRITE;
/*!40000 ALTER TABLE `bankers` DISABLE KEYS */;
/*!40000 ALTER TABLE `bankers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `blocked_bundles`
--

DROP TABLE IF EXISTS `blocked_bundles`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `blocked_bundles` (
  `bundle_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`bundle_id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `blocked_bundles`
--

LOCK TABLES `blocked_bundles` WRITE;
/*!40000 ALTER TABLE `blocked_bundles` DISABLE KEYS */;
/*!40000 ALTER TABLE `blocked_bundles` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `blocked_domains`
--

DROP TABLE IF EXISTS `blocked_domains`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `blocked_domains` (
  `domain_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`domain_id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `blocked_domains`
--

LOCK TABLES `blocked_domains` WRITE;
/*!40000 ALTER TABLE `blocked_domains` DISABLE KEYS */;
/*!40000 ALTER TABLE `blocked_domains` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `blocked_ips`
--

DROP TABLE IF EXISTS `blocked_ips`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `blocked_ips` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `ip` varchar(32) NOT NULL,
  `reason` varchar(32) NOT NULL,
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  UNIQUE KEY `ip_uk` (`ip`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `blocked_ips`
--

LOCK TABLES `blocked_ips` WRITE;
/*!40000 ALTER TABLE `blocked_ips` DISABLE KEYS */;
/*!40000 ALTER TABLE `blocked_ips` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `budget_transactions`
--

DROP TABLE IF EXISTS `budget_transactions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `budget_transactions` (
  `banker_id` int(10) unsigned NOT NULL,
  `slot_id` int(10) unsigned NOT NULL,
  `line_item_id` int(10) unsigned NOT NULL,
  `reserved` bigint(20) unsigned NOT NULL,
  `commited` bigint(20) unsigned NOT NULL,
  `retired` bigint(20) unsigned NOT NULL,
  PRIMARY KEY (`banker_id`,`slot_id`,`line_item_id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `budget_transactions`
--

LOCK TABLES `budget_transactions` WRITE;
/*!40000 ALTER TABLE `budget_transactions` DISABLE KEYS */;
/*!40000 ALTER TABLE `budget_transactions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `bundle_pool_bundles`
--

DROP TABLE IF EXISTS `bundle_pool_bundles`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bundle_pool_bundles` (
  `pool_id` int(10) unsigned NOT NULL,
  `bundle_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`pool_id`,`bundle_id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bundle_pool_bundles`
--

LOCK TABLES `bundle_pool_bundles` WRITE;
/*!40000 ALTER TABLE `bundle_pool_bundles` DISABLE KEYS */;
INSERT INTO `bundle_pool_bundles` VALUES (1,1);
/*!40000 ALTER TABLE `bundle_pool_bundles` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `bundle_pools`
--

DROP TABLE IF EXISTS `bundle_pools`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bundle_pools` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `vars` varchar(1024) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MEMORY AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bundle_pools`
--

LOCK TABLES `bundle_pools` WRITE;
/*!40000 ALTER TABLE `bundle_pools` DISABLE KEYS */;
INSERT INTO `bundle_pools` VALUES (1,'bundle-pool-some','key1=value1\nkey2=');
/*!40000 ALTER TABLE `bundle_pools` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `bundles`
--

DROP TABLE IF EXISTS `bundles`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bundles` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `bundle` varchar(255) NOT NULL,
  `iwr` double NOT NULL DEFAULT '0',
  `eir` double NOT NULL DEFAULT '0',
  `fr` double NOT NULL DEFAULT '0',
  `ctr` double NOT NULL DEFAULT '0',
  `wr` double NOT NULL DEFAULT '0',
  `ir` double NOT NULL DEFAULT '0',
  `category_id` int(10) unsigned NOT NULL DEFAULT '0',
  `age_rating` int(10) unsigned NOT NULL DEFAULT '0',
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  UNIQUE KEY `uk_bundle` (`bundle`)
) ENGINE=MEMORY AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bundles`
--

LOCK TABLES `bundles` WRITE;
/*!40000 ALTER TABLE `bundles` DISABLE KEYS */;
INSERT INTO `bundles` VALUES (1,'bundle-some',0,0,0,0,0,0,0,0,'2021-10-08 15:41:25');
/*!40000 ALTER TABLE `bundles` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `campaigns`
--

DROP TABLE IF EXISTS `campaigns`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `campaigns` (
  `id` int(10) unsigned NOT NULL,
  `account_id` int(10) unsigned NOT NULL,
  `name` varchar(255) NOT NULL,
  `spent` bigint(20) unsigned NOT NULL,
  `spent_today` bigint(20) unsigned NOT NULL,
  `limit_type` enum('budget','imps','clicks','events') NOT NULL DEFAULT 'budget',
  `limit_value` bigint(20) unsigned NOT NULL DEFAULT '0',
  `limit_value_daily` bigint(20) unsigned NOT NULL DEFAULT '0',
  `limit_event_id` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_date_begin` datetime DEFAULT NULL,
  `limit_date_end` datetime DEFAULT NULL,
  `add_moat` tinyint(1) NOT NULL DEFAULT '0',
  `add_protected` TINYINT(1) unsigned NOT NULL DEFAULT '0',
  `status` enum('active','blocked','paused','deleted') NOT NULL,
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `campaigns`
--

LOCK TABLES `campaigns` WRITE;
/*!40000 ALTER TABLE `campaigns` DISABLE KEYS */;
INSERT INTO `campaigns` VALUES (1,1,'campaign name',0,0,'budget',100000000,10000000,0,'2021-10-07 00:00:00',NULL,0,0,'active','2021-10-08 15:41:23','2021-10-08 15:41:23'),(2,1,'DV',0,0,'imps',40,30,0,'2021-11-29 00:00:00',NULL,1,0,'active','2021-11-29 19:17:12','2021-12-14 14:50:53');
/*!40000 ALTER TABLE `campaigns` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `categories`
--

DROP TABLE IF EXISTS `categories`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `categories` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `parent_id` int(10) unsigned NOT NULL,
  `iab_code` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `ak_parent_id` (`parent_id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `categories`
--

LOCK TABLES `categories` WRITE;
/*!40000 ALTER TABLE `categories` DISABLE KEYS */;
/*!40000 ALTER TABLE `categories` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creative_categories`
--

DROP TABLE IF EXISTS `creative_categories`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `creative_categories` (
  `creative_id` int(10) unsigned NOT NULL,
  `category_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`creative_id`,`category_id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `creative_categories`
--

LOCK TABLES `creative_categories` WRITE;
/*!40000 ALTER TABLE `creative_categories` DISABLE KEYS */;
/*!40000 ALTER TABLE `creative_categories` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creatives`
--

DROP TABLE IF EXISTS `creatives`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `creatives` (
  `id` int(10) unsigned NOT NULL,
  `campaign_id` int(10) unsigned NOT NULL,
  `format_id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `click_url` varchar(1024) NOT NULL,
  `crid` varchar(255) NOT NULL,
  `width` int(11) NOT NULL,
  `height` int(11) NOT NULL,
  `min_width` int(11) NOT NULL,
  `min_height` int(11) NOT NULL,
  `max_width` int(11) NOT NULL,
  `max_height` int(11) NOT NULL,
  `params` varchar(8192) NOT NULL,
  `code` varchar(8192) NOT NULL,
  `adomain` varchar(255) NOT NULL,
  `bundle` varchar(255) DEFAULT NULL,
  `app_name` varchar(255) DEFAULT NULL,
  `store_url` varchar(255) DEFAULT NULL,
  `duration` int(10) unsigned NOT NULL,
  `bitrate` int(10) unsigned NOT NULL,
  `codec` varchar(255) DEFAULT NULL,
  `mime_type` varchar(255) NOT NULL,
  `linearity` enum('linear','non-linear') NOT NULL DEFAULT 'linear',
  `api` enum('none','1','2','3','4','5','6') NOT NULL DEFAULT 'none',
  `attributes` set('1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17') NOT NULL,
  `banner_type` enum('1','2','3','4') NOT NULL,
  `moderate` enum('pending','active','blocked') NOT NULL DEFAULT 'pending',
  `inventory_type` set('rewarded_video','interstitial_video','native_video') DEFAULT NULL,
  `skip_sec` int(10) unsigned DEFAULT 0,
  `endcard` tinyint(1) NOT NULL DEFAULT 0,
  `type` enum('banner','video','native') DEFAULT NULL,
  `limit_inventory_type` set('rewarded','interstitial') DEFAULT NULL,
  `min_skip_duration` int(10) unsigned NOT NULL DEFAULT '0',
  `companion_type` enum('none','static','html','iframe') NOT NULL DEFAULT 'none',
  `companion_uri` varchar(255) DEFAULT NULL,
  `companion_mime` varchar(255) NOT NULL,
  `companion_width` int(10) unsigned NOT NULL DEFAULT '0',
  `companion_height` int(10) unsigned NOT NULL DEFAULT '0',
  `status` enum('active','blocked','paused','deleted') NOT NULL DEFAULT 'active',
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `creatives`
--

LOCK TABLES `creatives` WRITE;
/*!40000 ALTER TABLE `creatives` DISABLE KEYS */;
INSERT INTO `creatives` VALUES
(1,1,1,'creative name','http://click','',320,240,0,0,0,0,'{\n\"impressions\": [{\n\"id\": \"tp\",\n\"url\": \"http://imp_tp\"\n}],\n\"creatives\": [{\n\"id\": \"1\",\n\"duration\": \"00:15:00\",\n\"media_files\": [{\n\"id\": \"1\",\n\"delivery\": \"progressive\",\n\"type\": \"video/mp4\",\n\"bitrate\": \"300\",\n\"codec\": \"h264\",\n\"url\": \"http://media_file_url\"\n}],\n\"tracking\": [{\n\"event\": \"start\",\n\"url\": \"http://tracking?start\"\n}, {\n\"event\": \"complete\",\n\"url\": \"http://tracking?complete\"\n}],\n\"click_through\": \"http://click_through\",\n\"click_tracking\": [{\n\"id\": \"tp\",\n\"url\": \"http://click_tracking?tp\"\n}]\n}],\n\"extensions\": [{\n\"type\": \"startTime\",\n\"value\": \"00:00\"\n}, {\n\"type\": \"addClick\",\n\"value\": \"http://add_click\"\n}]\n}','','adomain','','','',30,300,NULL,'video/mp4','linear','1','1,3,5,7','1','pending',NULL,0,0,NULL,NULL,0,'none','','',0,0,'active','2021-10-08 15:41:23','2021-10-08 15:41:23'),(2,2,2,'DV #360','http://127.0.0.1/','',1280,720,0,0,0,0,'{"id":"1666","impressions":[],"creatives":[{"id":"1666","duration":"00:00:20","click_through":"https://hyperad.tech","media_files":[{"id":"1666","type":"video/mp4","codec":"H.264/MPEG-4 AVC","width":"1280","height":"720","bitrate":"986","url":"https://s.dsp-cabinet.hyperad.tech/creatives/e7a0b77d-a74c-4930-9720-a3d1978ed8e0.mp4","delivery":"progressive"}],"tracking":[],"click_tracking":[]}]}','','127.0.0.1',NULL,NULL,NULL,20,986,'H.264/MPEG-4 AVC','video/mp4','linear','none',NULL,'none','pending',NULL,0,0,'video',NULL,5,'none',NULL,NULL,0,0,'active','2021-11-29 19:18:06','2021-11-29 19:18:07');
/*!40000 ALTER TABLE `creatives` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `currencies`
--

DROP TABLE IF EXISTS `currencies`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `currencies` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `code` varchar(255) NOT NULL,
  `rate` bigint(20) unsigned NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MEMORY AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `currencies`
--

LOCK TABLES `currencies` WRITE;
/*!40000 ALTER TABLE `currencies` DISABLE KEYS */;
INSERT INTO `currencies` VALUES (1,'US Dollars','USD',1000000),(2,'Wooden RUB','RUB',13424);
/*!40000 ALTER TABLE `currencies` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `domain_pool_domains`
--

DROP TABLE IF EXISTS `domain_pool_domains`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `domain_pool_domains` (
  `pool_id` int(10) unsigned NOT NULL,
  `domain_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`pool_id`,`domain_id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `domain_pool_domains`
--

LOCK TABLES `domain_pool_domains` WRITE;
/*!40000 ALTER TABLE `domain_pool_domains` DISABLE KEYS */;
/*!40000 ALTER TABLE `domain_pool_domains` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `domain_pools`
--

DROP TABLE IF EXISTS `domain_pools`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `domain_pools` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `vars` varchar(1024) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `domain_pools`
--

LOCK TABLES `domain_pools` WRITE;
/*!40000 ALTER TABLE `domain_pools` DISABLE KEYS */;
/*!40000 ALTER TABLE `domain_pools` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `domains`
--

DROP TABLE IF EXISTS `domains`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `domains` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `domain` varchar(255) NOT NULL,
  `iwr` double NOT NULL DEFAULT '0',
  `eir` double NOT NULL DEFAULT '0',
  `fr` double NOT NULL DEFAULT '0',
  `ctr` double NOT NULL DEFAULT '0',
  `wr` double NOT NULL DEFAULT '0',
  `ir` double NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `uk_domain` (`domain`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `domains`
--

LOCK TABLES `domains` WRITE;
/*!40000 ALTER TABLE `domains` DISABLE KEYS */;
/*!40000 ALTER TABLE `domains` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `dsps`
--

DROP TABLE IF EXISTS `dsps`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `dsps` (
  `id` int(10) unsigned NOT NULL,
  `currency_id` int(10) unsigned NOT NULL,
  `name` varchar(255) NOT NULL,
  `fee` double unsigned NOT NULL DEFAULT '0',
  `min_bid_floor` double unsigned NOT NULL DEFAULT '0',
  `adomain` varchar(255) NOT NULL,
  `vars` varchar(255) NOT NULL,
  `handler` enum('default','rb') NOT NULL DEFAULT 'default',
  `skip_zero_ifa` tinyint(1) unsigned NOT NULL DEFAULT '0',
  `status` enum('active','blocked','deleted') NOT NULL DEFAULT 'active',
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dsps`
--

LOCK TABLES `dsps` WRITE;
/*!40000 ALTER TABLE `dsps` DISABLE KEYS */;
INSERT INTO `dsps` VALUES (2,1,'dsp name rtb',5,1,'','','default',0,'blocked','2021-10-08 15:41:26','2021-10-08 15:41:26'),(1,1,'dsp name direct',0,0,'','','default',0,'blocked','2021-10-08 15:41:27','2021-10-08 15:41:27'),(3,2,'dsp name rtb rub',5,1,'','','default',0,'blocked','2021-10-08 15:41:28','2021-10-08 15:41:28'),(4,1,'dsp name rtb_rew',5,1,'','','default',0,'blocked','2021-10-08 15:41:29','2021-10-08 15:41:29'),(5,1,'dsp name rtb cache',5,1,'','','default',0,'blocked','2021-10-08 15:41:30','2021-10-08 15:41:30');
/*!40000 ALTER TABLE `dsps` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `endpoint_stats`
--

DROP TABLE IF EXISTS `endpoint_stats`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `endpoint_stats` (
  `endpoint_id` int(10) unsigned NOT NULL,
  `req` int(10) unsigned NOT NULL,
  `res` int(10) unsigned NOT NULL,
  `bids` int(10) unsigned NOT NULL,
  `wins` int(10) unsigned NOT NULL,
  `imps` int(10) unsigned NOT NULL,
  `clicks` int(10) unsigned NOT NULL,
  `day` date NOT NULL,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`endpoint_id`,`day`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `endpoint_stats`
--

LOCK TABLES `endpoint_stats` WRITE;
/*!40000 ALTER TABLE `endpoint_stats` DISABLE KEYS */;
/*!40000 ALTER TABLE `endpoint_stats` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `endpoint_tests`
--

DROP TABLE IF EXISTS `endpoint_tests`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `endpoint_tests` (
  `endpoint_id` int(10) unsigned NOT NULL,
  `test_id` int(10) unsigned NOT NULL,
  `percent_live` int(10) unsigned NOT NULL,
  `begin` datetime DEFAULT NULL,
  `end` datetime DEFAULT NULL,
  `transient_endpoint` enum('yes','no') NOT NULL DEFAULT 'no',
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`endpoint_id`,`test_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `endpoint_tests`
--

LOCK TABLES `endpoint_tests` WRITE;
/*!40000 ALTER TABLE `endpoint_tests` DISABLE KEYS */;
/*!40000 ALTER TABLE `endpoint_tests` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `channels`
--

CREATE TABLE `channels` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `geo_pool_id` int(10) unsigned NOT NULL,
  `limit_country_type` enum('none','allow','reject') NOT NULL DEFAULT 'none',
  `limit_state_type` enum('none','allow','reject') NOT NULL DEFAULT 'none',
  `limit_city_type` enum('none','allow','reject') NOT NULL DEFAULT 'none',
  `limit_ssp_type` enum('none','allow','reject') NOT NULL DEFAULT 'none',
  `limit_device_types_type` enum('none','allow','reject') NOT NULL DEFAULT 'none',
  `limit_traffic_type` enum('none','app','site') NOT NULL DEFAULT 'none',
  `limit_imp_type` enum('none','banner','video','native') NOT NULL DEFAULT 'none',
  `limit_api` set('1','2','3','4','5','6','7') NOT NULL DEFAULT '1,2,3,4,5,6,7',
  `limit_protocols` set('1','2','3','4','5','6','7','8','9','10') NOT NULL DEFAULT '1,2,3,4,5,6,7,8,9,10',
  `limit_companion_type` set('1','2','3') DEFAULT NULL,
  `limit_allowed_os` enum('all','android','ios') NOT NULL DEFAULT 'all',
  `limit_rewarded` enum('none','rewarded','not_rewarded') NOT NULL DEFAULT 'none',
  `limit_scored_publishers` tinyint(1) unsigned NOT NULL DEFAULT '0',
  `limit_with_domain_only` tinyint(1) NOT NULL DEFAULT '0',
  `limit_interstitial` tinyint(1) NOT NULL DEFAULT '0',
  `limit_screen_position` enum('none','portrait','landscape') NOT NULL DEFAULT 'none',
  `min_iwr` double unsigned NOT NULL DEFAULT '0',
  `min_eir` double unsigned NOT NULL DEFAULT '0',
  `min_fr` double unsigned NOT NULL DEFAULT '0',
  `min_ctr` double unsigned NOT NULL DEFAULT '0',
  `min_wr` double unsigned NOT NULL DEFAULT '0',
  `min_ir` double unsigned NOT NULL DEFAULT '0',
  `min_width` int(10) unsigned NOT NULL DEFAULT '0',
  `min_height` int(10) unsigned NOT NULL DEFAULT '0',
  `status` enum('active','blocked','deleted') NOT NULL DEFAULT 'active',
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;
CREATE TABLE `channel_endpoints` (
  `channel_id` int(10) unsigned NOT NULL,
  `endpoint_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`channel_id`,`endpoint_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
CREATE TABLE `channel_bundle_pools` (
  `channel_id` int(10) unsigned NOT NULL,
  `pool_id` int(10) unsigned NOT NULL,
  `type` enum('allow','reject') NOT NULL DEFAULT 'allow',
  PRIMARY KEY (`channel_id`,`pool_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
CREATE TABLE `channel_cities` (
  `channel_id` int(10) unsigned NOT NULL,
  `city_id` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`channel_id`,`city_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
CREATE TABLE `channel_states` (
  `channel_id` int(10) unsigned NOT NULL,
  `state_id` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`channel_id`,`state_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
CREATE TABLE `channel_countries` (
  `channel_id` int(10) unsigned NOT NULL,
  `country_id` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`channel_id`,`country_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
CREATE TABLE `channel_deal_ids` (
  `channel_id` int(10) unsigned NOT NULL,
  `deal_id` varchar(255) NOT NULL,
  PRIMARY KEY (`channel_id`,`deal_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
CREATE TABLE `channel_device_types` (
  `channel_id` int(10) unsigned NOT NULL,
  `device_type_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`channel_id`,`device_type_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
CREATE TABLE `channel_domain_pools` (
  `channel_id` int(10) unsigned NOT NULL,
  `pool_id` int(10) unsigned NOT NULL,
  `type` enum('allow','reject') NOT NULL DEFAULT 'allow',
  PRIMARY KEY (`channel_id`,`pool_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
CREATE TABLE `channel_google_billing_ids` (
  `channel_id` int(10) unsigned NOT NULL,
  `billing_id` varchar(255) NOT NULL,
  PRIMARY KEY (`channel_id`,`billing_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
CREATE TABLE `channel_ifa_pools` (
  `channel_id` int(10) unsigned NOT NULL,
  `pool_id` int(10) unsigned NOT NULL,
  `type` enum('allow','reject') NOT NULL DEFAULT 'allow',
  PRIMARY KEY (`channel_id`,`pool_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
CREATE TABLE `channel_mime_types` (
  `channel_id` int(10) unsigned NOT NULL,
  `mime_type_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`channel_id`,`mime_type_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
CREATE TABLE `channel_segments` (
  `channel_id` int(10) unsigned NOT NULL,
  `segment_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`channel_id`,`segment_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
CREATE TABLE `channel_ssps` (
  `channel_id` int(10) unsigned NOT NULL,
  `ssp_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`channel_id`,`ssp_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Table structure for table `endpoints`
--

DROP TABLE IF EXISTS `endpoints`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `endpoints` (
  `id` int(10) unsigned NOT NULL,
  `dsp_id` int(10) unsigned NOT NULL,
  `currency_id` int(10) unsigned NOT NULL,
  `creative_cache_id` int(10) unsigned NOT NULL,
  `name` varchar(255) NOT NULL,
  `uri` varchar(255) NOT NULL,
  `priority_level` int(10) DEFAULT '0',
  `limit_bid` bigint(20) unsigned NOT NULL,
  `limit_cached_count` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_cached_timeout` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_wo_creative_count` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_wo_creative_timeout` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_imp_count` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_imp_timeout` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_creative_imp_count` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_creative_imp_timeout` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_req_daily` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_imps_daily` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_companion_iframe_timeout` int(10) unsigned NOT NULL DEFAULT '0',
  `request_type` enum('rtb','direct','wrapper') NOT NULL DEFAULT 'rtb',
  `response_type` enum('rtb','vast') NOT NULL DEFAULT 'rtb',
  `reuse_creatives` enum('disabled','single','per_ssp','custom') NOT NULL DEFAULT 'disabled',
  `reuse_max_age` int(10) unsigned NOT NULL DEFAULT '0',
  `reuse_v2` tinyint(1) unsigned NOT NULL DEFAULT '0',
  `reuse_fill_rate` int(10) unsigned NOT NULL DEFAULT '0',
  `reuse_imp_lt_res` tinyint(1) unsigned NOT NULL DEFAULT '1',
  `reuse_if_dsp200` tinyint(1) unsigned NOT NULL DEFAULT '0',
  `reuse_global_settings` tinyint(1) unsigned NOT NULL DEFAULT '1',
  `reuse_city_line_ttl` int(10) unsigned NOT NULL DEFAULT '0',
  `reuse_state_line_ttl` int(10) unsigned NOT NULL DEFAULT '0',
  `reuse_country_line_ttl` int(10) unsigned NOT NULL DEFAULT '0',
  `reuse_use_timeout` int(10) unsigned NOT NULL DEFAULT '0',
  `google_pending_bids` int(10) unsigned NOT NULL DEFAULT '0',
  `companion_iframe_uri` varchar(255) NOT NULL,
  `vars` varchar(255) NOT NULL,
  `ignore_bid_price` tinyint(1) NOT NULL DEFAULT '0',
  `add_moat` tinyint(1) NOT NULL DEFAULT '0',
  `add_protected` TINYINT(1) unsigned NOT NULL DEFAULT '0',
  `mark_all_rewarded` tinyint(1) NOT NULL DEFAULT '0',
  `allow_rotten` tinyint(1) NOT NULL DEFAULT '0',
  `resolve_wrappers` tinyint(1) NOT NULL DEFAULT '0',
  `test` tinyint(1) unsigned NOT NULL DEFAULT '0',
  `toss_source` tinyint(1) unsigned NOT NULL DEFAULT '0',
  `limit_rps` INT unsigned NOT NULL DEFAULT '0',
  `upstream_strategy` enum('default', 'detach') NOT NULL DEFAULT 'default',
  `status` enum('active','blocked','deleted') NOT NULL DEFAULT 'active',
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  KEY `ak_dsp_id` (`dsp_id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `endpoints`
--

LOCK TABLES `endpoints` WRITE;
/*!40000 ALTER TABLE `endpoints` DISABLE KEYS */;
INSERT INTO `endpoints` VALUES
(2,2,0,0,'endpoint rtb','@URL@/rtb_rtb',0,3000000,0,0,0,0,0,0,0,0,0,0,0,'rtb','rtb','disabled',0,1,0,0,0,1,0,0,0,0,0,'','',0,0,0,0,0,0,1,1,0,'default','active','2021-10-08 15:41:26','2021-10-08 15:41:26'),
(1,1,0,0,'endpoint direct','@URL@/vast_direct',0,2000000,0,0,0,0,0,0,0,0,0,0,0,'direct','vast','disabled',0,1,0,0,0,1,0,0,0,0,0,'','',0,0,0,0,0,0,1,1,0,'default','active','2021-10-08 15:41:27','2021-10-08 15:41:27'),
(3,3,2,0,'endpoint rtb rub','@URL@/rtb_rtb_rub',0,3000000,0,0,0,0,0,0,0,0,0,0,0,'rtb','rtb','disabled',0,1,0,0,0,1,0,0,0,0,0,'','',0,0,0,0,0,0,1,1,0,'default','active','2021-10-08 15:41:28','2021-10-08 15:41:28'),
(4,4,0,0,'endpoint rtb','@URL@/rtb_rtb_rew',0,3000000,0,0,0,0,0,0,0,0,0,0,0,'rtb','rtb','disabled',0,1,0,0,0,1,0,0,0,0,0,'','',0,0,0,1,0,0,1,1,0,'default','active','2021-10-08 15:41:29','2021-10-08 15:41:29'),
(5,5,0,0,'endpoint rtb','@URL@/rtb_rtb',0,3000000,0,0,0,0,0,0,0,0,0,0,0,'rtb','rtb','per_ssp',1,1,0,0,0,1,0,0,0,0,0,'','',0,0,0,0,0,0,1,1,0,'default','active','2021-10-08 15:41:30','2021-10-08 15:41:30');
/*!40000 ALTER TABLE `endpoints` ENABLE KEYS */;
UNLOCK TABLES;

LOCK TABLES `channels` WRITE, `channel_endpoints` WRITE, `channel_ssps` WRITE;
/*!40000 ALTER TABLE `channels` DISABLE KEYS */;
INSERT INTO `channels` VALUES
(1,0,'none','none','none','none','none','none','none','1,2,3,4,5,6,7','1,2,3,4,5,6,7,8,9,10',NULL,'all','none',0,0,0,'none',0,0,0,0,0,0,0,0,'active','2022-01-24 15:41:30','2022-01-24 15:41:30'),
(2,0,'none','none','none','none','none','none','none','1,2,3,4,5,6,7','1,2,3,4,5,6,7,8,9,10',NULL,'all','none',0,0,0,'none',0,0,0,0,0,0,0,0,'active','2022-01-24 15:41:30','2022-01-24 15:41:30');
INSERT INTO `channel_endpoints` VALUES
(1,1),(1,2),(1,3),(1,4),(1,5);
INSERT INTO `channel_ssps` VALUES (1, 1);
/*!40000 ALTER TABLE `channels` ENABLE KEYS */;
UNLOCK TABLES;


-- 

--
-- Table structure for table `external_creative_files`
--

DROP TABLE IF EXISTS `external_creative_files`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `external_creative_files` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `creative_id` int(10) unsigned NOT NULL,
  `media_file` varchar(1024) NOT NULL,
  `duration` int(10) unsigned NOT NULL DEFAULT '0',
  `bitrate` int(10) unsigned NOT NULL DEFAULT '0',
  `width` int(10) unsigned NOT NULL DEFAULT '0',
  `height` int(10) unsigned NOT NULL DEFAULT '0',
  `rotated_media_file` varchar(1024) NOT NULL,
  `tries` int(10) unsigned NOT NULL DEFAULT '0',
  `status` enum('new','sent','completed') NOT NULL DEFAULT 'new',
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `external_creative_files`
--

LOCK TABLES `external_creative_files` WRITE;
/*!40000 ALTER TABLE `external_creative_files` DISABLE KEYS */;
/*!40000 ALTER TABLE `external_creative_files` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `external_creative_ssps`
--

DROP TABLE IF EXISTS `external_creative_ssps`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `external_creative_ssps` (
  `creative_id` int(10) unsigned NOT NULL,
  `ssp_id` int(10) unsigned NOT NULL,
  `status` enum('new','allowed','rejected') NOT NULL DEFAULT 'new',
  PRIMARY KEY (`creative_id`,`ssp_id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `external_creative_ssps`
--

LOCK TABLES `external_creative_ssps` WRITE;
/*!40000 ALTER TABLE `external_creative_ssps` DISABLE KEYS */;
/*!40000 ALTER TABLE `external_creative_ssps` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `external_creative_stats`
--

DROP TABLE IF EXISTS `external_creative_stats`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `external_creative_stats` (
  `creative_id` int(10) unsigned NOT NULL,
  `bids` int(11) NOT NULL,
  `wins` int(11) NOT NULL,
  `imps` int(11) NOT NULL,
  `clicks` int(11) NOT NULL,
  `allows` int(11) NOT NULL DEFAULT '0',
  `rejects` int(11) NOT NULL DEFAULT '0',
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`creative_id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `external_creative_stats`
--

LOCK TABLES `external_creative_stats` WRITE;
/*!40000 ALTER TABLE `external_creative_stats` DISABLE KEYS */;
/*!40000 ALTER TABLE `external_creative_stats` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `external_creatives`
--

DROP TABLE IF EXISTS `external_creatives`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `external_creatives` (
  `id` int(10) unsigned NOT NULL,
  `category_id` int(10) unsigned NOT NULL DEFAULT '0',
  `dsp_id` int(10) unsigned NOT NULL DEFAULT '0',
  `endpoint_id` int(10) unsigned NOT NULL DEFAULT '0',
  `vast` mediumtext NOT NULL,
  `vast_origin` mediumtext NOT NULL,
  `media_file` varchar(1024) NOT NULL,
  `click_through` varchar(1024) NOT NULL,
  `landing_url` varchar(1024) NOT NULL,
  `adomain` varchar(255) NOT NULL,
  `bundle` varchar(255) NOT NULL,
  `wrapper_url` varchar(1024) NOT NULL,
  `title` varchar(255) NOT NULL,
  `description` varchar(255) NOT NULL,
  `icon` varchar(255) NOT NULL,
  `version` int(10) unsigned NOT NULL DEFAULT '0',
  `hash` int(10) unsigned NOT NULL DEFAULT '0',
  `duration` int(10) unsigned NOT NULL DEFAULT '0',
  `bitrate` int(10) unsigned NOT NULL DEFAULT '0',
  `width` int(10) unsigned NOT NULL DEFAULT '0',
  `height` int(10) unsigned NOT NULL DEFAULT '0',
  `vast_url` varchar(1024) NOT NULL,
  `google_advertiser` varchar(1024) NOT NULL,
  `google_response` varchar(1024) NOT NULL,
  `google_status` enum('new','approved','unapproved') NOT NULL DEFAULT 'new',
  `google_sent` timestamp NULL DEFAULT NULL,
  `google_checked` timestamp NULL DEFAULT NULL,
  `google_tries` int(10) unsigned NOT NULL DEFAULT '0',
  `google_pending_bids` int(10) unsigned NOT NULL DEFAULT '0',
  `ifa_chosen` tinyint(1) NOT NULL DEFAULT '0',
  `companion_iframe_uri` varchar(1024) NOT NULL,
  `mraid` varchar(1024) NOT NULL,
  `rotated_media_file` varchar(1024) NOT NULL,
  `rotated_tries` int(10) unsigned NOT NULL DEFAULT '0',
  `rotated_status` enum('new','send','completed') NOT NULL DEFAULT 'new',
  `limit_bid` bigint(20) unsigned NOT NULL,
  `cc2_last_line` ENUM('none','user','city','state','country') NOT NULL DEFAULT 'none',
  `status` enum('new','error','processed','moderated','purged') NOT NULL DEFAULT 'new',
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `external_creatives`
--

LOCK TABLES `external_creatives` WRITE;
/*!40000 ALTER TABLE `external_creatives` DISABLE KEYS */;
/*!40000 ALTER TABLE `external_creatives` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `formats`
--

DROP TABLE IF EXISTS `formats`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `formats` (
  `id` int(10) unsigned NOT NULL,
  `name` varchar(255) NOT NULL,
  `code` varchar(8192) NOT NULL,
  `params` varchar(8192) DEFAULT NULL,
  `type` enum('banner','video','native') NOT NULL,
  `status` enum('active','paused','deleted') NOT NULL DEFAULT 'active',
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `formats`
--

LOCK TABLES `formats` WRITE;
/*!40000 ALTER TABLE `formats` DISABLE KEYS */;
INSERT INTO `formats` VALUES (1,'Video','<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<VAST xmlns:xsi=\"https://www.w3.org/2001/XMLSchema-instance\" version=\"2.0\" xsi:noNamespaceSchemaLocation=\"vast.xsd\">\n<Ad id=\"{{id}}\">\n<InLine>\n<AdSystem>Bidderstack</AdSystem>\n<AdTitle>Ad</AdTitle>\n<Error><![CDATA[{{error}}]]></Error>\n{{begin impressions}}<Impression id=\"{{id}}\"><![CDATA[{{url}}]]></Impression>{{end}}\n<Creatives>\n{{begin creatives}}\n<Creative id=\"{{id}}\" AdID=\"{{id}}\">\n<Linear>\n<Duration>{{duration}}</Duration>\n<MediaFiles>{{begin media_files}}<MediaFile id=\"{{id}}\" delivery=\"{{delivery}}\" type=\"{{type}}\" bitrate=\"{{bitrate}}\" width=\"{{width}}\" height=\"{{height}}\" codec=\"{{codec}}\"><![CDATA[{{url}}]]></MediaFile>{{end}}</MediaFiles>\n<TrackingEvents>{{begin tracking}}<Tracking event=\"{{event}}\"><![CDATA[{{url}}]]></Tracking>{{end}}</TrackingEvents>\n<VideoClicks><ClickThrough><![CDATA[{{click_through}}]]></ClickThrough>{{begin click_tracking}}<ClickTracking id=\"{{id}}\"><![CDATA[{{url}}]]></ClickTracking>{{end}}</VideoClicks>\n</Linear>\n</Creative>\n{{end}}\n</Creatives>\n<Extensions>{{begin extensions}}<Extension type=\"{{type}}\"><![CDATA[{{value}}]]></Extension>{{end}}</Extensions>\n</InLine>\n</Ad>\n</VAST>\n','{}','video','active','2021-10-08 15:41:23','2021-10-08 15:41:23'),(2,'VAST','<?xml version="1.0" encoding="UTF-8"?><VAST xmlns:xsi="https://www.w3.org/2001/XMLSchema-instance" version="2.0" xsi:noNamespaceSchemaLocation="vast.xsd"><Ad id="{{id}}"><InLine><AdSystem>Bidderstack</AdSystem><Error id="bstk-error"><![CDATA[https://track.bidderstack.com/error?code=[ERRORCODE]]]></Error>{{begin impressions}}<Impression id="{{id}}"><![CDATA[{{url}}]]></Impression>{{end}}<Creatives>{{begin creatives}}<Creative id="{{id}}" AdID="{{id}}"><Linear><Duration>{{duration}}</Duration><MediaFiles>{{begin media_files}}<MediaFile id="{{id}}" delivery="{{delivery}}" type="{{type}}" bitrate="{{bitrate}}" width="{{width}}" height="{{height}}"><![CDATA[{{url}}]]></MediaFile>{{end}}</MediaFiles><TrackingEvents>{{begin tracking}}<Tracking event="{{event}}"><![CDATA[{{url}}]]></Tracking>{{end}}</TrackingEvents><VideoClicks><ClickThrough><![CDATA[{{click_through}}]]></ClickThrough>{{begin click_tracking}}<ClickTracking id="{{id}}"><![CDATA[{{url}}]]></ClickTracking>{{end}}</VideoClicks></Linear></Creative>{{if survey_url}}<Creative id="{{id}}" AdID="{{id}}"><CompanionAds><Companion id="{{id}}" width="{{#slot_width}}" height="{{#slot_height}}"><IFrameResource><![CDATA[{{survey_url}}]]></IFrameResource></Companion></CompanionAds></Creative>{{end}}{{if static_uri}}<Creative id="{{id}}" AdID="{{id}}"><CompanionAds><Companion width="{{#slot_width}}" height="{{#slot_height}}"{{if companion_width}} assetWidth="{{companion_width}}"{{end}}{{if companion_height}} assetHeight="{{companion_height}}"{{end}}>{{if static_uri}}<StaticResource{{if companion_mime}} creativeType="{{companion_mime}}"{{end}}><![CDATA[{{static_uri}}]]></StaticResource>{{end}}<CompanionClickThrough><![CDATA[{{click_through}}]]></CompanionClickThrough>{{begin click_tracking}}<ClickTracking id="{{id}}"><![CDATA[{{url}}&from=endcard]]></ClickTracking>{{end}}</Companion></CompanionAds></Creative>{{end}}{{if html_uri}}<Creative id="{{id}}" AdID="{{id}}"><CompanionAds><Companion width="{{#slot_width}}" height="{{#slot_height}}"{{if companion_width}} assetWidth="{{companion_width}}"{{end}}{{if companion_height}} assetHeight="{{companion_height}}"{{end}}>{{if html_uri}}<HTMLResource><![CDATA[{{html_uri}}]]></HTMLResource>{{end}}<CompanionClickThrough><![CDATA[{{click_through}}]]></CompanionClickThrough></Companion></CompanionAds></Creative>{{end}}{{if iframe_uri}}<Creative id="{{id}}" AdID="{{id}}"><CompanionAds><Companion width="{{#slot_width}}" height="{{#slot_height}}"{{if companion_width}} assetWidth="{{companion_width}}"{{end}}{{if companion_height}} assetHeight="{{companion_height}}"{{end}}>{{if iframe_uri}}<IFrameResource><![CDATA[{{iframe_uri}}]]></IFrameResource>{{end}}<CompanionClickThrough><![CDATA[{{click_through}}]]></CompanionClickThrough></Companion></CompanionAds></Creative>{{end}}{{end}}</Creatives><Extensions>{{moat_extension}}{{protected_extension}}</Extensions></InLine></Ad></VAST>',NULL,'video','active','2017-08-28 13:33:07','2021-10-14 12:50:46');
/*!40000 ALTER TABLE `formats` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `geo_pool_geos`
--

DROP TABLE IF EXISTS `geo_pool_geos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `geo_pool_geos` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `pool_id` int(10) unsigned NOT NULL,
  `country_id` int(10) unsigned NOT NULL,
  `state_id` int(10) unsigned NOT NULL,
  `city_id` int(10) unsigned NOT NULL,
  `type` enum('allow','reject') NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `pool_uk` (`pool_id`,`country_id`,`state_id`,`city_id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `geo_pool_geos`
--

LOCK TABLES `geo_pool_geos` WRITE;
/*!40000 ALTER TABLE `geo_pool_geos` DISABLE KEYS */;
/*!40000 ALTER TABLE `geo_pool_geos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `geo_pools`
--

DROP TABLE IF EXISTS `geo_pools`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `geo_pools` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `geo_pools`
--

LOCK TABLES `geo_pools` WRITE;
/*!40000 ALTER TABLE `geo_pools` DISABLE KEYS */;
/*!40000 ALTER TABLE `geo_pools` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ifa_pools`
--

DROP TABLE IF EXISTS `ifa_pools`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ifa_pools` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `vars` varchar(1024) NOT NULL,
  `ifa` varchar(1024) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ifa_pools`
--

LOCK TABLES `ifa_pools` WRITE;
/*!40000 ALTER TABLE `ifa_pools` DISABLE KEYS */;
/*!40000 ALTER TABLE `ifa_pools` ENABLE KEYS */;
UNLOCK TABLES;


--
-- Table structure for table `line_item_categories`
--

DROP TABLE IF EXISTS `line_item_categories`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `line_item_categories` (
  `line_item_id` int(10) unsigned NOT NULL,
  `category_id` int(10) unsigned NOT NULL
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `line_item_categories`
--

LOCK TABLES `line_item_categories` WRITE;
/*!40000 ALTER TABLE `line_item_categories` DISABLE KEYS */;
/*!40000 ALTER TABLE `line_item_categories` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `line_item_creatives`
--

DROP TABLE IF EXISTS `line_item_creatives`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `line_item_creatives` (
  `line_item_id` int(10) unsigned NOT NULL,
  `creative_id` int(10) unsigned NOT NULL
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `line_item_creatives`
--

LOCK TABLES `line_item_creatives` WRITE;
/*!40000 ALTER TABLE `line_item_creatives` DISABLE KEYS */;
INSERT INTO `line_item_creatives` VALUES (1,1),(2,2);
/*!40000 ALTER TABLE `line_item_creatives` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `line_item_models`
--

DROP TABLE IF EXISTS `line_item_models`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `line_item_models` (
  `line_item_id` int(10) unsigned NOT NULL,
  `models` varchar(255) NOT NULL,
  `type` enum('allow','reject') NOT NULL DEFAULT 'allow',
  PRIMARY KEY (`line_item_id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `line_item_models`
--

LOCK TABLES `line_item_models` WRITE;
/*!40000 ALTER TABLE `line_item_models` DISABLE KEYS */;
/*!40000 ALTER TABLE `line_item_models` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `line_items`
--

DROP TABLE IF EXISTS `line_items`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `line_items` (
  `id` int(10) unsigned NOT NULL,
  `campaign_id` int(10) unsigned NOT NULL,
  `name` varchar(255) NOT NULL,
  `spent` bigint(20) unsigned NOT NULL,
  `spent_today` bigint(20) unsigned NOT NULL,
  `priority_level` int(10) DEFAULT '0',
  `limit_bid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `limit_deal_id` varchar(255) DEFAULT NULL,
  `limit_value` bigint(20) unsigned NOT NULL DEFAULT '0',
  `limit_value_daily` bigint(20) unsigned NOT NULL DEFAULT '0',
  `limit_date_begin` datetime DEFAULT NULL,
  `limit_date_end` datetime DEFAULT NULL,
  `limit_day_hours` char(168) NOT NULL DEFAULT '111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111',
  `limit_delivery` enum('asap','even') NOT NULL DEFAULT 'asap',
  `limit_fq_imps_count` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_fq_imps_interval` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_fq_clicks_count` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_fq_clicks_interval` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_uniq_imps` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_uniq_clicks` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_bid_interval` int(10) unsigned NOT NULL DEFAULT '0',
  `limit_categories_type` enum('none','allow','reject') NOT NULL DEFAULT 'none',
  `limit_device_types_type` enum('none','allow','reject') NOT NULL DEFAULT 'none',
  `limit_session_depth` varchar(255) DEFAULT NULL,
  `limit_locale` varchar(255) DEFAULT NULL,
  `allow_video_skip` tinyint(1) NOT NULL DEFAULT '1',
  `min_skip_duration` int(10) unsigned NOT NULL,
  `allow_placements` set('1','2','3','4','5') DEFAULT NULL,
  `allow_startdelay` set('1','2','3','4') DEFAULT NULL,
  `alowed_playbackmethod` set('1','2','3','4','5','6') DEFAULT NULL,
  `special_type` enum('none','matching') NOT NULL DEFAULT 'none',
  `status` enum('active','blocked','paused','deleted') NOT NULL DEFAULT 'active',
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `line_items`
--

LOCK TABLES `line_items` WRITE;
/*!40000 ALTER TABLE `line_items` DISABLE KEYS */;
INSERT INTO `line_items` VALUES
(1,1,'line item 1 name',0,0,0,2000000,'',70000000,7000000,'2021-10-07 00:00:00',NULL,'111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111','asap',0,0,0,0,0,0,0,'none','none','','',1,0,'','','','none','active','2021-10-08 15:41:23','2021-10-08 15:41:23'),
(2,2,'Double Ver',0,0,0,1000000,NULL,20,10,'2021-11-29 00:00:00',NULL,'111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111','asap',0,0,0,0,0,0,0,'none','none',NULL,NULL,1,0,NULL,NULL,NULL,'none','active','2021-11-29 19:17:25','2021-12-14 14:44:17');
/*!40000 ALTER TABLE `line_items` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mime_types`
--

DROP TABLE IF EXISTS `mime_types`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mime_types` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `mime_types`
--

LOCK TABLES `mime_types` WRITE;
/*!40000 ALTER TABLE `mime_types` DISABLE KEYS */;
/*!40000 ALTER TABLE `mime_types` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pool_bundles`
--

DROP TABLE IF EXISTS `pool_bundles`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pool_bundles` (
  `bundle_id` int(10) unsigned NOT NULL,
  `pool_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`bundle_id`,`pool_id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pool_bundles`
--

LOCK TABLES `pool_bundles` WRITE;
/*!40000 ALTER TABLE `pool_bundles` DISABLE KEYS */;
INSERT INTO `pool_bundles` VALUES (1,1);
/*!40000 ALTER TABLE `pool_bundles` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pool_domains`
--

DROP TABLE IF EXISTS `pool_domains`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pool_domains` (
  `domain_id` int(10) unsigned NOT NULL,
  `pool_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`pool_id`,`domain_id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pool_domains`
--

LOCK TABLES `pool_domains` WRITE;
/*!40000 ALTER TABLE `pool_domains` DISABLE KEYS */;
/*!40000 ALTER TABLE `pool_domains` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pools`
--

DROP TABLE IF EXISTS `pools`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pools` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `account_id` int(10) unsigned NOT NULL,
  `name` varchar(255) NOT NULL,
  `type` enum('bundle','smart_user','user','domain') NOT NULL,
  `value` varchar(255) DEFAULT NULL,
  `date_from` date DEFAULT NULL,
  `date_to` date DEFAULT NULL,
  `amount_values` int(10) unsigned NOT NULL DEFAULT '0',
  `is_auto_updated` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `include_new_users` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `status` enum('active','preparing','deleted') NOT NULL DEFAULT 'preparing',
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  KEY `account_id` (`account_id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pools`
--

LOCK TABLES `pools` WRITE;
/*!40000 ALTER TABLE `pools` DISABLE KEYS */;
INSERT INTO `pools` VALUES (1, 1, 'test domain', 'domain', 'nix.ru', '2019-06-03', '2029-07-03', 1, 0, 0, 'preparing', '2019-07-03 15:49:54', '2019-08-13 16:42:57');
/*!40000 ALTER TABLE `pools` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `properties`
--

DROP TABLE IF EXISTS `properties`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `properties` (
  `key` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  `value` varchar(8192) NOT NULL,
  PRIMARY KEY (`key`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `properties`
--

LOCK TABLES `properties` WRITE;
/*!40000 ALTER TABLE `properties` DISABLE KEYS */;
INSERT INTO `properties` VALUES ('vast2_code','vast2_code','<?xml version=\"1.0\" encoding=\"UTF-8\"?><VAST xmlns:xsi=\"https://www.w3.org/2001/XMLSchema-instance\" version=\"2.0\" xsi:noNamespaceSchemaLocation=\"vast.xsd\"><Ad id=\"{{id}}\"><InLine><AdSystem>Bidderstack</AdSystem><AdTitle>Ad</AdTitle><Error><![CDATA[{{error}}]]></Error>{{begin impressions}}<Impression id=\"{{id}}\"><![CDATA[{{url}}]]></Impression>{{end}}<Creatives>{{begin creatives}}<Creative id=\"{{id}}\" AdID=\"{{id}}\"><Linear><Duration>{{duration}}</Duration><MediaFiles>{{begin media_files}}<MediaFile id=\"{{id}}\" delivery=\"{{delivery}}\" type=\"{{type}}\" bitrate=\"{{bitrate}}\" width=\"{{width}}\" height=\"{{height}}\" codec=\"{{codec}}\"><![CDATA[{{url}}]]></MediaFile>{{end}}</MediaFiles><TrackingEvents>{{begin tracking}}<Tracking event=\"{{event}}\"><![CDATA[{{url}}]]></Tracking>{{end}}</TrackingEvents><VideoClicks><ClickThrough><![CDATA[{{click_through}}]]></ClickThrough>{{begin click_tracking}}<ClickTracking id=\"{{id}}\"><![CDATA[{{url}}]]></ClickTracking>{{end}}</VideoClicks></Linear></Creative>{{end}}</Creatives><Extensions>{{begin extensions}}<Extension type=\"{{type}}\"><![CDATA[{{value}}]]></Extension>{{end}}</Extensions></InLine></Ad></VAST>'),('vast_js_player','VAST JS player','<script type=\"text/javascript\">\n(function() {\n var h = document.getElementsByTagName(\"head\")[0] || document.documentElement, s = document.createElement(\"script\");\n s.async = true; s.src = document.location.protocol + \"//files.bidderstack.com/player.min.js\";\n h.insertBefore(s, h.firstChild);\n var t = setInterval(function(){\n if (typeof(Player) == \"undefined\") {\n return;\n }\n clearInterval(t);\n var player = new Player(document.getElementById(\"bdrstk_player\"), \"{{vast_uri}}\");\n }, 100);\n})();\n</script> '),('vast_mraid_player','VAST MRAID player','<script src=\"//files.bidderstack.com/mraid_player.min.js\"></script> \n<div id=\"bdrstk_player\"></div>\n<script type=\"text/javascript\">\n var t = setInterval(function(){\n if (typeof(MraidPlayer) === \"undefined\") {\n console.log(\"undefined\");\n return;\n }\n clearInterval(t);\n var player = new MraidPlayer(document.getElementById(\"bdrstk_player\"), \"{{vast_uri}}\");\n }, 100);\n</script>\n'),('cm_rb_to_gdn','cm_rb_to_gdn','yes'),('cc_user_line_ttl','Время жизни в линии кеша пользователя','2'),('cc_city_line_ttl','Время жизни в линии кеша города','0'),('cc_state_line_ttl','Время жизни в линии кеша области','0'),('cc_country_line_ttl','Время жизни в линии кеша страны','0'),('chosen_priority_level', 'Приоритет для избранных ifa', '10');
/*!40000 ALTER TABLE `properties` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `segments`
--

DROP TABLE IF EXISTS `segments`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `segments` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `ttl` int(10) unsigned NOT NULL DEFAULT '0',
  `rules` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `segments`
--

LOCK TABLES `segments` WRITE;
/*!40000 ALTER TABLE `segments` DISABLE KEYS */;
/*!40000 ALTER TABLE `segments` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spent_transactions`
--

DROP TABLE IF EXISTS `spent_transactions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `spent_transactions` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `banker_id` int(10) unsigned NOT NULL,
  `line_item_id` int(10) unsigned NOT NULL,
  `type` enum('spent','correction','compaction') NOT NULL DEFAULT 'spent',
  `coins` bigint(20) NOT NULL,
  `imps` bigint(20) NOT NULL,
  `clicks` bigint(20) NOT NULL,
  `events` bigint(20) NOT NULL,
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spent_transactions`
--

LOCK TABLES `spent_transactions` WRITE;
/*!40000 ALTER TABLE `spent_transactions` DISABLE KEYS */;
/*!40000 ALTER TABLE `spent_transactions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ssp_bid_tunes`
--

DROP TABLE IF EXISTS `ssp_bid_tunes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ssp_bid_tunes` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `bundle` varchar(255) NOT NULL,
  `ssp_id` int(10) unsigned NOT NULL,
  `bidprice` int(20) unsigned NOT NULL,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ssp_bid_tunes`
--

LOCK TABLES `ssp_bid_tunes` WRITE;
/*!40000 ALTER TABLE `ssp_bid_tunes` DISABLE KEYS */;
/*!40000 ALTER TABLE `ssp_bid_tunes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ssp_bundle_pools`
--

DROP TABLE IF EXISTS `ssp_bundle_pools`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ssp_bundle_pools` (
  `ssp_id` int(10) unsigned NOT NULL,
  `pool_id` int(10) unsigned NOT NULL,
  `country_id` int(10) unsigned NOT NULL,
  `type` enum('allow','reject') NOT NULL DEFAULT 'allow',
  PRIMARY KEY (`ssp_id`,`pool_id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ssp_bundle_pools`
--

LOCK TABLES `ssp_bundle_pools` WRITE;
/*!40000 ALTER TABLE `ssp_bundle_pools` DISABLE KEYS */;
/*!40000 ALTER TABLE `ssp_bundle_pools` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ssp_domain_pools`
--

DROP TABLE IF EXISTS `ssp_domain_pools`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ssp_domain_pools` (
  `ssp_id` int(10) unsigned NOT NULL,
  `pool_id` int(10) unsigned NOT NULL,
  `country_id` int(10) unsigned NOT NULL,
  `type` enum('allow','reject') NOT NULL DEFAULT 'allow',
  PRIMARY KEY (`ssp_id`,`pool_id`)
) ENGINE=MEMORY DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ssp_domain_pools`
--

LOCK TABLES `ssp_domain_pools` WRITE;
/*!40000 ALTER TABLE `ssp_domain_pools` DISABLE KEYS */;
/*!40000 ALTER TABLE `ssp_domain_pools` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ssps`
--

DROP TABLE IF EXISTS `ssps`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ssps` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(10) unsigned NOT NULL,
  `name` varchar(255) NOT NULL,
  `alias` varchar(255) NOT NULL,
  `token` varchar(255) NOT NULL,
  `limit_bid` bigint(20) unsigned NOT NULL DEFAULT '0',
  `timeout_ms` int(10) unsigned NOT NULL DEFAULT '0',
  `vast_return_type` enum('adm','nurl','vast') NOT NULL DEFAULT 'adm',
  `vast_pricing` enum('none','add','remove') NOT NULL DEFAULT 'none',
  `seatbid_seat` varchar(255) NOT NULL,
  `handler` enum('default','google','mopub','bidswitch','taboola','unity','rb','tiktok','iron') NOT NULL DEFAULT 'default',
  `dont_bid_floor_eq_limit` tinyint(1) unsigned NOT NULL DEFAULT '0',
  `match_cookies` tinyint(1) unsigned NOT NULL DEFAULT '0',
  `trust_to_losses` tinyint(1) NOT NULL DEFAULT '1',
  `allowed_ext_creatives_only` tinyint(1) NOT NULL DEFAULT '1',
  `add_moat` tinyint(1) NOT NULL DEFAULT '0',
  `add_protected` TINYINT(1) unsigned NOT NULL DEFAULT '0',
  `creative_from_cache` tinyint(1) NOT NULL DEFAULT '0',
  `optimize_bid` enum('none','by_bidfloor','by_wr','by_wr_slope') NOT NULL DEFAULT 'none',
  `optimize_bid_ecpm` bigint(20) unsigned NOT NULL DEFAULT '0',
  `optimize_bid_step` bigint(20) unsigned NOT NULL DEFAULT '10000',
  optimize_bid_add bigint(20) unsigned NOT NULL DEFAULT '0',
  `status` enum('active','blocked','paused','deleted') NOT NULL DEFAULT 'active',
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  KEY `ak_user_id` (`user_id`)
) ENGINE=MEMORY AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ssps`
--

LOCK TABLES `ssps` WRITE;
/*!40000 ALTER TABLE `ssps` DISABLE KEYS */;
INSERT INTO `ssps` VALUES
(1,1,'default_ssp_name','default_ssp','',3000000,500,'adm','none','seat','default',0,0,1,0,0,0,0,'none',0,1,0,'active','2021-10-08 15:41:24','2021-10-08 15:41:24'),
(2,2,'unity_ssp_name','unity_ssp','',3000000,500,'adm','none','seat','unity',0,0,1,0,0,0,0,'none',0,1,0,'active','2021-10-08 15:41:24','2021-10-08 15:41:24'),
(3,3,'google_ssp_name','google_ssp','',3000000,500,'adm','none','seat','google',0,0,1,0,0,0,0,'none',0,1,0,'active','2021-10-08 15:41:24','2021-10-08 15:41:24'),
(4,4,'mopub_ssp_name','mopub_ssp','',3000000,500,'adm','none','seat','mopub',0,0,1,0,0,0,0,'none',0,1,0,'active','2021-10-08 15:41:24','2021-10-08 15:41:24'),
(5,5,'tiktok_ssp_name','tiktok_ssp','',3000000,500,'adm','none','seat','tiktok',0,0,1,0,0,0,0,'none',0,1,0,'active','2021-10-08 15:41:24','2021-10-08 15:41:24'),
(6,6,'iron_ssp_name','iron_ssp','',3000000,500,'adm','none','seat','iron',0,0,1,0,0,0,0,'none',0,1,0,'active','2021-10-08 15:41:24','2021-10-08 15:41:24'),
(7,0,'DoubleVerify','doubleverify','',0,500,'adm','none','','default',0,0,1,0,0,0,0,'none',1000000,100000,0,'active','2021-11-29 19:08:41','2021-11-30 14:16:39');
/*!40000 ALTER TABLE `ssps` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `report_ssps`
--

DROP TABLE IF EXISTS `report_ssps`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `report_ssps` (
  `ssp_id` int(10) unsigned NOT NULL,
  `req` int(10) unsigned NOT NULL,
  `res` int(10) unsigned NOT NULL,
  `dsp_req` int(10) unsigned NOT NULL,
  `dsp_res` int(10) unsigned NOT NULL,
  `wins` int(10) unsigned NOT NULL,
  `losses` int(10) unsigned NOT NULL,
  `imps` int(10) unsigned NOT NULL,
  `clicks` int(10) unsigned NOT NULL,
  `events_start` int(10) unsigned NOT NULL DEFAULT '0',
  `events_25` int(10) unsigned NOT NULL,
  `events_50` int(10) unsigned NOT NULL,
  `events_75` int(10) unsigned NOT NULL,
  `events_100` int(10) unsigned NOT NULL,
  `price` double unsigned NOT NULL,
  `price_ssp` double unsigned NOT NULL,
  `hour` datetime NOT NULL,
  `day` date NOT NULL,
  PRIMARY KEY (`hour`,`ssp_id`) USING BTREE,
  KEY `ak_day` (`day`) USING BTREE
) ENGINE=MEMORY AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `report_ssps`
--

LOCK TABLES `report_ssps` WRITE;
/*!40000 ALTER TABLE `report_ssps` DISABLE KEYS */;
/*!40000 ALTER TABLE `report_ssps` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

ALTER TABLE `endpoints` ADD COLUMN `headers` varchar(1024) NOT NULL AFTER `vars`;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-10-08 18:42:58

CREATE TABLE `ifa_pool_ifa` (
  `pool_id` int(11) unsigned NOT NULL,
  `ifa` varchar(64) NOT NULL,
  PRIMARY KEY (`pool_id`, `ifa`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `ml_models` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `engine` enum ('libsvm') NOT NULL,
  `vars` text NOT NULL,
  `model` text NOT NULL,
  `encoder` text NOT NULL,
  `features` text NOT NULL,
  `status` enum('active','blocked','paused','deleted') NOT NULL DEFAULT 'active',
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO ml_models (id, name, engine, vars, model, encoder, features, status) VALUES
(null, 'Test model', 'libsvm', 'puid99=1', 'svm_type one_class
kernel_type rbf
gamma 0.001
nr_class 2
total_sv 511
rho 103.78637156399805
SV
1 1:7 2:52 4:3 6:59 7:2 
1 1:7 2:52 3:1 4:8 5:1 6:59 7:22 
1 1:7 3:1 4:10 5:1 7:23 
1 1:7 4:1 5:5 6:59 7:21 
1 1:7 4:6 5:6 6:2 7:1 
1 1:23 2:33 3:1 4:10 7:7 
0.91102616254473889 1:19 2:33 3:1 4:10 5:6 7:2 
1 1:7 2:52 4:6 5:4 6:58 7:23 
1 2:50 4:6 6:59 7:21 
1 1:7 2:52 4:5 5:6 7:1 
1 1:7 4:4 5:4 6:59 7:22 
1 1:7 4:6 6:1 
1 2:8 4:2 5:6 6:29 
1 1:22 2:33 3:1 4:10 5:3 6:59 7:7 
1 1:7 4:6 5:2 7:23 
1 1:23 2:33 3:1 4:10 5:6 6:45 
0.70858767655142485 1:7 2:52 4:5 5:6 7:22 
1 1:7 2:52 4:5 6:59 7:22 
1 1:7 2:52 4:4 5:5 6:56 
1 2:51 4:6 5:5 6:31 7:23 
1 1:7 4:6 5:3 6:1 7:1 
1 1:7 4:6 6:1 
1 1:7 3:1 4:10 5:5 6:59 
1 2:46 4:3 6:2 
1 1:7 3:1 4:10 5:6 6:29 
1 1:7 2:52 4:7 5:2 6:57 
0.88514304094399621 1:23 2:33 3:1 4:10 5:4 6:16 7:22 
1 1:7 2:52 3:1 4:10 6:58 7:22 
1 2:50 4:6 5:2 6:2 7:23 
1 1:7 2:52 4:3 5:5 6:56 
1 1:23 2:33 3:1 4:10 5:5 6:49 
1 1:23 2:33 3:1 4:10 5:3 6:2 7:22 
1 1:23 2:33 3:1 4:10 5:4 6:1 7:18 
1 1:7 3:1 4:10 5:4 6:3 
1 2:51 4:7 5:4 6:2 7:22 
1 1:23 2:33 3:1 4:9 5:1 6:2 7:20 
1 1:23 2:33 3:1 4:10 5:6 6:3 7:5 
1 1:7 3:1 4:10 5:6 6:27 
1 1:23 2:33 3:1 4:8 5:6 6:43 7:22 
1 2:46 4:7 6:2 
1 1:7 4:4 7:22 
1 1:23 2:33 3:1 4:10 5:3 6:54 7:20 
1 1:23 2:33 3:1 4:10 5:1 6:35 7:2 
1 1:7 2:1 3:1 4:10 5:2 6:58 
1 1:7 3:1 4:9 5:3 6:59 7:22 
1 1:19 2:33 3:1 4:10 7:23 
1 1:7 3:1 4:10 5:5 6:58 7:1 
1 1:23 2:33 3:1 4:10 5:6 6:51 7:19 
1 2:46 4:7 5:6 7:23 
1 1:7 2:52 3:1 4:10 6:59 7:2 
1 2:50 4:7 6:34 7:23 
1 1:7 2:1 3:1 4:10 5:5 6:58 7:23 
1 1:23 2:33 3:1 4:10 5:4 6:39 7:22 
1 1:23 2:33 3:1 4:10 5:5 6:56 7:20 
1 1:7 4:5 5:6 6:59 
1 2:46 4:4 5:4 7:1 
1 1:7 2:52 3:1 4:10 5:5 7:2 
1 1:7 5:1 6:6 7:1 
1 2:51 4:2 5:1 6:57 7:22 
0.73360621788850322 2:15 4:6 5:6 7:1 
1 1:7 4:4 5:3 6:59 7:22 
0.98883828497599702 1:7 2:52 4:6 5:2 6:1 7:1 
1 1:7 2:52 4:6 5:1 6:58 7:23 
1 1:7 2:52 3:1 4:10 5:6 6:54 
1 1:7 2:52 3:1 4:10 5:2 6:59 7:22 
1 1:7 2:52 4:2 5:6 7:23 
1 1:7 4:2 5:6 6:20 
1 1:7 2:52 4:2 5:1 6:2 7:23 
1 1:7 4:6 5:1 7:23 
1 1:23 2:33 3:1 4:10 5:2 6:1 7:5 
1 1:7 2:52 4:6 5:5 6:59 7:22 
1 1:7 2:52 3:1 4:10 6:1 
0.32106832971157928 1:7 4:2 5:1 6:35 7:23 
1 1:7 2:52 4:7 5:5 6:1 7:1 
1 1:7 2:52 3:1 4:9 5:2 7:23 
1 1:23 2:33 3:1 4:10 5:6 6:25 
1 1:7 2:52 4:6 7:23 
0.75864727958304712 1:7 2:52 4:1 5:1 6:54 7:23 
1 1:7 5:4 6:54 7:23 
1 1:7 3:1 4:8 6:1 7:23 
1 1:23 2:33 3:1 4:10 5:1 6:59 7:2 
1 1:7 2:52 4:7 7:23 
1 1:7 4:6 5:6 6:59 7:1 
1 1:7 3:1 4:10 5:3 7:23 
1 2:50 4:4 5:5 6:7 
1 1:23 2:33 3:1 4:10 5:4 6:29 7:2 
1 1:23 2:33 3:1 4:10 5:5 6:42 
1 1:7 2:1 4:4 5:1 7:23 
1 1:23 2:33 3:1 4:10 5:4 6:46 7:21 
1 1:7 3:1 4:10 5:5 6:58 7:1 
1 1:7 2:52 3:1 4:10 6:4 
1 1:7 3:1 4:10 5:6 6:59 7:2 
1 1:7 4:6 6:59 7:22 
1 1:7 4:5 5:1 6:59 7:22 
1 1:23 2:33 3:1 4:10 5:2 7:5 
1 1:7 4:3 5:6 6:59 7:1 
1 2:50 4:6 6:35 
1 2:50 4:4 5:2 6:31 
1 2:51 4:5 5:3 6:39 
1 1:7 4:6 5:5 6:58 7:23 
1 1:7 4:5 5:5 6:59 
1 1:7 3:1 4:8 5:1 6:59 7:22 
1 2:51 4:6 6:38 
1 1:7 3:1 4:11 6:24 
1 1:7 2:52 4:4 5:6 6:59 7:1 
1 1:7 2:52 4:2 5:2 7:23 
1 2:50 4:4 5:2 7:23 
0.93172046286403476 1:7 3:1 4:10 6:31 
1 1:7 3:1 4:10 5:3 6:57 7:23 
0.92749937454697551 1:7 2:52 4:5 6:57 7:1 
1 2:46 4:7 7:23 
1 1:7 4:1 5:1 6:57 7:22 
1 1:7 2:52 4:6 5:6 7:23 
1 2:46 4:1 5:4 6:58 7:2 
1 2:14 5:4 7:22 
1 1:7 2:52 4:3 5:5 6:59 7:22 
1 1:7 2:1 3:1 4:10 7:23 
1 1:7 2:52 3:1 4:10 5:1 7:22 
1 1:7 4:4 5:1 7:23 
1 1:7 3:1 4:10 5:6 6:31 
1 1:7 4:6 6:59 7:22 
1 1:23 2:33 3:1 4:8 5:4 7:6 
1 2:4 4:2 5:5 6:37 
1 1:7 2:52 3:1 4:10 5:6 6:58 7:22 
1 2:15 4:1 6:2 
1 1:7 3:1 4:9 5:4 6:1 7:1 
1 2:50 4:7 5:4 6:58 7:22 
1 1:7 2:52 4:2 5:2 6:1 7:2 
1 1:7 3:1 4:10 5:3 6:59 
1 2:8 4:4 5:6 6:1 7:1 
1 1:7 2:52 4:7 6:59 7:22 
1 1:7 4:5 5:4 6:58 7:23 
0.8855502372106443 1:7 2:52 5:6 6:43 7:23 
1 1:7 4:5 6:1 7:23 
1 1:7 4:6 5:2 7:23 
1 1:7 4:5 5:6 7:22 
1 1:23 2:33 3:1 4:8 5:1 6:31 7:22 
1 1:7 2:52 4:2 6:53 
1 1:23 2:33 3:1 4:10 5:1 6:31 7:21 
1 1:7 4:7 5:6 6:59 
1 1:7 3:1 4:10 5:4 6:57 
0.80451609481554631 2:51 4:6 6:41 7:23 
1 1:23 2:33 3:1 4:10 5:3 6:58 
1 2:51 4:6 6:17 
1 1:7 3:1 4:10 5:6 7:2 
1 1:7 4:2 6:26 7:23 
1 1:7 2:52 4:1 5:4 7:21 
1 1:7 2:52 4:3 5:1 6:58 7:22 
1 1:7 2:52 4:7 5:2 7:23 
1 1:7 3:1 4:10 6:5 
1 1:7 2:52 4:4 6:2 
1 2:51 4:3 5:5 6:12 
1 1:22 2:33 3:1 4:8 5:4 6:25 7:23 
1 1:7 4:6 5:2 7:23 
1 1:23 2:33 3:1 4:10 5:1 6:48 7:2 
1 1:7 2:52 3:1 4:10 6:2 
1 1:18 2:33 3:1 4:10 6:1 
1 1:23 2:33 3:1 4:10 5:6 7:12 
1 1:7 4:2 5:5 6:29 7:23 
1 1:23 2:33 3:1 4:10 5:3 6:59 7:11 
1 1:7 2:52 3:1 4:8 5:2 6:59 7:22 
1 1:7 2:52 4:1 5:1 6:57 7:22 
1 1:7 4:2 6:24 
1 2:50 4:5 5:1 7:23 
1 1:7 3:1 4:10 5:6 6:59 7:2 
1 1:7 4:1 5:4 7:22 
1 1:7 4:6 6:59 7:22 
1 1:7 4:6 5:1 7:23 
1 1:7 2:52 4:6 5:6 7:23 
1 1:7 3:1 4:10 5:5 6:59 7:22 
1 1:7 3:1 4:10 6:59 7:22 
0.57967093373288447 2:46 4:6 5:6 6:58 7:1 
1 2:50 4:7 7:21 
1 1:7 2:1 3:1 4:10 5:4 6:1 7:1 
1 1:7 4:5 5:6 6:1 7:23 
1 1:7 2:52 5:6 6:59 7:19 
1 2:4 4:7 5:3 6:58 
1 1:7 2:52 4:6 5:6 6:1 7:23 
0.46373692987460974 1:7 3:1 4:10 5:5 7:3 
1 1:7 2:52 4:5 5:4 7:23 
1 1:7 3:1 4:10 6:1 
1 2:46 4:3 5:6 6:57 
0.52921047814660049 1:7 2:1 5:6 6:19 7:23 
1 1:7 4:6 5:5 6:59 7:23 
1 1:23 2:33 3:1 4:9 5:2 6:11 
1 1:7 4:1 5:6 6:55 7:1 
1 1:7 2:52 4:6 5:5 6:59 7:22 
0.2270191057557521 1:7 2:52 4:7 5:2 6:59 7:22 
1 1:7 4:1 5:3 6:59 7:21 
1 1:7 2:52 4:4 5:3 6:59 7:1 
1 1:18 2:33 3:1 4:10 6:59 7:22 
0.41117901099079168 1:23 2:33 3:1 4:10 5:3 6:57 7:13 
1 1:7 4:6 5:6 7:2 
1 1:7 2:1 3:1 4:10 5:1 7:23 
1 1:7 3:1 4:10 5:6 6:30 
1 1:7 2:52 4:4 5:5 6:59 7:22 
1 1:7 4:4 5:2 6:4 
1 1:7 2:52 4:1 5:6 6:1 7:2 
1 1:7 2:52 3:1 4:10 5:6 6:57 
1 1:7 2:1 4:3 5:6 6:59 7:22 
1 1:7 4:6 5:4 7:1 
1 1:7 3:1 4:10 5:6 6:27 
1 1:7 4:7 5:5 6:58 7:23 
1 1:7 2:1 4:5 6:2 
1 1:7 4:6 7:23 
1 1:7 2:52 4:6 6:59 7:22 
1 1:7 4:1 5:6 6:59 7:20 
1 2:46 4:2 5:1 7:23 
1 2:46 4:3 6:2 
1 2:50 4:6 6:58 7:22 
1 1:7 2:52 4:5 6:59 7:22 
1 1:7 2:52 4:5 5:5 7:1 
1 1:7 2:52 3:1 4:8 5:6 6:59 7:22 
1 1:7 2:52 4:6 5:1 7:23 
1 1:7 4:1 6:31 
1 1:7 2:52 3:1 4:8 5:6 7:23 
1 1:7 3:1 4:10 5:1 7:1 
1 1:23 2:33 3:1 4:10 5:4 6:4 7:1 
1 1:7 3:1 4:10 6:59 7:22 
0.31710388925273258 1:7 3:1 4:10 6:57 7:1 
1 1:7 2:52 3:1 4:10 5:2 7:22 
1 1:7 4:4 5:6 6:2 7:23 
0.33166978808046566 2:46 4:1 5:6 6:58 7:21 
1 1:23 2:33 3:1 4:10 6:49 
1 1:7 3:1 4:9 5:1 6:58 7:23 
1 1:7 2:52 3:1 4:10 6:4 
1 1:7 3:1 4:10 6:33 7:23 
1 2:46 4:5 6:1 
1 1:7 4:7 6:59 7:22 
1 1:7 4:6 5:5 6:59 7:23 
1 1:7 2:1 3:1 4:8 5:6 6:58 
1 2:6 4:7 7:23 
1 1:7 2:52 3:1 4:10 6:1 7:23 
1 1:7 3:1 4:10 5:6 7:22 
1 1:7 2:52 4:4 5:1 6:1 7:23 
1 2:8 4:6 5:6 6:59 7:1 
1 1:7 4:4 5:5 6:58 7:23 
1 1:7 3:1 4:10 6:29 7:23 
1 2:51 4:7 5:5 6:26 
1 2:50 4:2 5:6 6:19 
1 1:7 4:6 5:1 6:59 7:1 
1 1:7 3:1 4:10 6:2 7:23 
1 2:46 4:1 5:6 6:2 7:23 
1 1:7 3:1 4:10 6:29 
1 1:7 2:52 3:1 4:10 6:3 
1 2:50 4:6 5:5 6:53 
1 2:50 4:4 6:59 7:21 
1 1:23 2:33 3:1 4:10 5:3 7:15 
1 1:7 2:52 4:6 6:59 7:1 
1 1:23 2:33 3:1 4:10 5:6 6:24 7:21 
1 1:7 4:6 5:2 6:3 
1 1:23 2:33 3:1 4:10 5:3 6:59 7:9 
1 1:7 2:52 4:6 5:6 7:23 
1 1:7 4:2 5:2 6:2 7:23 
1 1:7 3:1 4:8 7:23 
1 1:23 2:33 3:1 4:10 5:1 6:2 7:23 
1 1:7 3:1 4:10 5:1 7:23 
1 1:7 4:3 5:6 6:1 7:23 
1 2:46 5:6 6:59 7:20 
1 1:7 4:6 5:6 6:1 7:23 
1 1:7 4:6 5:4 6:58 7:23 
1 1:7 3:1 4:10 5:1 7:22 
1 1:7 4:1 5:1 6:57 7:22 
1 1:7 3:1 4:10 5:6 7:23 
1 1:7 2:52 3:1 4:10 5:2 6:59 7:22 
1 1:7 2:2 4:2 5:6 6:1 7:1 
1 1:7 4:2 5:2 6:1 7:23 
0.83515225674351279 1:7 3:1 4:10 5:6 6:59 7:21 
1 1:7 2:52 3:1 4:9 5:2 6:59 7:22 
1 1:7 2:52 4:2 6:57 7:22 
1 1:7 2:52 4:5 5:2 6:59 7:23 
1 1:23 2:33 3:1 4:10 6:18 
1 1:7 2:52 3:1 4:8 5:3 6:59 7:22 
1 2:50 4:4 6:39 
1 1:7 2:1 3:1 4:10 6:1 
1 1:19 2:33 3:1 4:10 5:6 7:23 
1 1:7 4:3 6:59 7:21 
0.012525173059973905 2:50 4:3 5:6 6:58 7:4 
1 1:7 4:1 6:2 7:22 
1 1:7 3:1 4:10 5:6 6:1 7:1 
1 2:51 4:7 5:5 6:28 7:23 
1 1:7 2:52 3:1 4:10 5:5 6:57 7:23 
1 1:7 4:6 6:59 7:22 
1 1:23 2:33 3:1 4:8 5:2 6:8 7:23 
1 2:15 4:4 5:3 6:59 
1 1:7 2:2 6:34 7:23 
1 1:7 4:4 5:2 6:59 7:22 
1 1:7 3:1 4:10 6:58 7:22 
1 2:24 4:2 6:59 7:22 
1 1:19 2:33 3:1 4:8 5:6 7:23 
1 1:23 2:33 3:1 4:10 5:2 6:48 
0.28699523361366741 1:7 4:1 6:13 
1 1:7 2:52 4:7 5:6 6:1 7:23 
1 2:8 4:1 5:3 6:30 7:23 
1 1:21 2:3 3:1 4:10 5:3 6:32 7:12 
1 1:7 3:1 4:10 5:5 6:59 
1 1:7 2:52 4:7 5:5 6:59 7:23 
1 1:7 3:1 4:10 6:30 7:23 
1 1:7 2:52 4:4 5:3 6:56 
1 2:15 4:5 6:1 
1 1:7 3:1 4:10 6:30 
1 1:7 4:7 5:6 7:1 
1 2:50 4:6 5:4 6:59 7:1 
1 2:50 4:6 5:1 6:58 7:21 
1 1:7 4:4 5:6 7:2 
1 1:7 2:52 3:1 4:10 5:2 6:1 7:23 
1 1:7 2:1 3:1 4:10 5:5 6:59 
1 1:7 2:52 4:6 6:1 
1 1:7 2:52 3:1 4:10 5:1 6:59 
1 2:46 4:6 5:5 7:1 
1 2:46 4:6 5:4 6:59 7:23 
1 1:7 2:1 3:1 4:10 5:2 6:59 7:1 
1 1:7 2:1 3:1 4:10 5:3 6:59 
1 1:7 4:7 6:2 
1 2:50 4:5 5:1 6:27 7:23 
1 1:7 3:1 4:10 5:5 6:57 
1 1:7 3:1 4:10 6:3 
1 1:7 3:1 4:10 6:2 7:23 
1 1:7 2:52 4:3 5:1 6:57 
1 1:7 4:5 5:6 7:22 
1 2:51 4:7 5:2 6:58 7:21 
1 2:46 4:7 5:6 6:59 7:1 
1 1:23 2:33 3:1 4:10 5:2 6:18 7:22 
1 1:7 4:6 5:5 6:59 
1 1:7 2:52 4:6 6:59 7:1 
1 1:7 4:2 5:1 6:59 
1 1:7 2:52 3:1 4:10 6:2 
1 1:7 4:1 5:4 6:56 7:23 
0.43577671745441604 1:7 4:3 5:3 7:22 
1 1:7 3:1 4:10 5:6 6:57 
1 1:7 2:52 3:1 4:9 5:5 6:59 7:22 
1 1:7 2:52 4:2 5:5 6:59 7:3 
1 1:7 3:1 4:10 5:4 6:58 7:23 
1 2:50 4:6 6:31 7:23 
1 1:7 3:1 4:10 5:4 6:59 7:23 
0.085965765047585629 2:8 4:5 5:4 6:58 7:23 
0.26929683433414275 2:50 4:5 5:3 6:31 
1 1:7 4:6 6:59 7:22 
1 1:7 2:52 3:1 4:10 5:1 6:1 7:1 
1 1:7 3:1 4:10 7:3 
1 1:7 4:3 5:4 6:58 7:1 
1 2:18 4:3 5:1 6:58 7:23 
1 1:7 2:52 4:6 5:2 7:23 
1 2:46 4:6 6:2 
1 1:7 3:1 4:10 5:5 7:22 
1 1:7 3:1 4:10 5:5 6:57 
1 2:51 4:7 5:6 6:18 
1 1:7 2:52 4:4 5:5 6:59 7:2 
1 1:7 4:3 5:6 6:58 
1 1:7 4:1 5:2 7:3 
1 1:7 3:1 4:10 5:6 6:58 
1 1:7 2:52 3:1 4:10 5:1 6:56 
1 1:7 4:2 6:6 
1 1:7 5:2 6:55 7:23 
1 1:7 2:52 4:7 5:1 7:23 
1 2:50 4:6 5:3 6:56 7:23 
1 1:1 2:33 3:1 4:10 5:6 6:59 
1 1:7 4:2 6:32 
1 1:7 2:52 5:5 6:3 7:23 
1 2:15 4:6 5:2 6:59 
1 1:7 2:52 4:1 5:2 6:57 7:2 
1 1:7 2:52 3:1 4:10 5:4 6:3 
1 1:7 3:1 4:10 5:4 6:59 7:22 
1 1:7 4:6 5:6 6:1 7:23 
1 1:7 4:6 5:3 6:59 
1 1:7 4:7 5:1 7:23 
1 1:7 2:52 4:6 5:4 6:59 7:1 
1 1:7 2:52 4:2 5:5 6:59 
1 1:7 4:7 5:2 7:23 
1 2:51 4:5 5:6 6:28 7:22 
0.61814185513426712 2:24 4:6 5:3 6:59 
1 1:7 2:52 4:7 5:1 6:56 
1 1:7 4:2 6:3 
1 1:7 2:52 3:1 4:6 5:6 7:23 
1 2:51 4:3 5:3 6:34 7:23 
1 1:7 2:2 5:5 6:58 7:22 
1 1:23 2:33 3:1 4:10 5:3 6:41 7:22 
1 2:50 4:5 6:29 
1 2:50 4:6 5:6 6:1 7:23 
1 1:7 4:4 5:6 6:58 7:1 
1 1:7 2:52 4:7 5:6 6:1 7:23 
1 1:7 4:6 5:4 7:1 
1 1:7 2:52 4:4 5:2 7:23 
1 1:7 2:52 4:5 5:3 7:1 
1 1:7 3:1 4:10 6:3 
1 1:7 4:6 6:59 7:22 
1 1:7 4:4 5:6 6:2 7:23 
1 1:7 6:55 7:2 
1 1:7 2:52 4:1 5:3 6:55 
1 2:50 4:6 5:1 6:2 7:23 
1 1:23 2:33 3:1 4:10 5:5 6:5 7:2 
1 2:51 4:7 5:5 6:35 7:23 
1 2:51 4:4 6:32 7:23 
1 2:51 4:5 5:4 6:56 7:23 
1 1:7 2:52 4:1 5:4 6:57 7:2 
1 1:7 2:52 3:1 4:9 5:4 6:59 7:22 
0.74035286714210979 1:7 3:1 4:10 6:31 
1 2:50 4:6 5:4 6:29 
1 1:19 2:33 3:1 4:10 5:4 6:2 
1 1:7 2:1 3:1 4:10 5:6 6:59 
1 1:23 2:33 3:1 4:8 5:3 6:1 7:19 
1 1:7 4:5 6:59 7:1 
1 1:7 2:52 3:1 4:10 7:3 
1 1:7 2:52 4:4 5:5 7:2 
1 1:19 2:33 3:1 4:10 5:6 6:55 
1 1:7 3:1 4:10 5:4 6:4 
1 1:23 2:33 3:1 4:10 6:23 7:21 
1 2:50 4:7 6:1 
1 1:7 4:2 5:3 6:2 7:1 
1 1:23 2:33 3:1 4:10 5:2 6:59 7:13 
1 1:7 2:2 4:5 5:6 7:1 
1 1:7 2:52 4:2 5:4 7:22 
1 2:50 4:6 6:59 7:21 
1 2:50 4:3 6:1 7:3 
1 1:7 4:6 5:6 6:58 
1 1:7 4:3 5:2 6:56 
1 1:7 4:5 5:3 6:58 7:23 
1 1:7 2:52 4:4 5:6 6:57 7:1 
1 1:23 2:33 3:1 4:9 5:3 6:36 7:23 
1 1:23 2:33 3:1 4:10 5:2 6:29 7:2 
1 1:23 2:33 3:1 4:10 5:5 6:25 7:2 
1 1:7 2:52 3:1 4:10 6:1 7:23 
1 1:7 4:3 5:6 6:56 
1 1:7 3:1 4:10 5:6 7:23 
1 1:7 4:7 5:2 7:23 
1 1:7 3:1 4:10 6:31 7:23 
1 1:7 3:1 4:10 7:22 
1 1:23 2:33 3:1 4:9 5:4 7:21 
1 1:23 2:33 3:1 4:10 5:4 7:6 
1 1:7 3:1 4:10 5:6 7:22 
1 2:46 4:3 5:5 6:1 7:23 
1 1:7 3:1 4:9 6:4 
1 2:50 4:5 5:5 6:4 7:1 
1 1:7 4:1 5:5 6:28 7:23 
1 1:7 3:1 4:10 5:5 6:57 
1 1:7 2:52 3:1 4:10 5:6 6:59 7:21 
1 1:7 4:5 6:59 7:22 
1 1:7 4:3 5:1 7:23 
1 2:4 4:1 5:4 6:15 
1 1:7 4:6 5:4 6:58 
1 1:7 3:1 4:10 5:6 6:2 7:1 
1 1:7 2:52 4:5 5:5 6:59 7:22 
1 1:7 2:52 4:3 5:4 6:3 
1 1:7 2:52 4:4 5:6 6:1 7:1 
1 1:7 2:52 4:6 5:1 7:23 
1 1:7 4:2 5:4 6:32 7:23 
1 1:7 3:1 4:11 5:4 6:58 7:22 
1 1:7 4:3 5:1 6:1 7:23 
1 1:7 2:52 3:1 4:10 5:4 6:57 7:1 
1 1:7 2:52 4:5 6:1 7:23 
1 2:51 4:1 5:3 7:7 
1 1:7 3:1 4:10 5:5 6:59 7:1 
1 1:7 2:52 3:1 4:10 5:3 6:58 7:22 
1 1:23 2:33 3:1 4:10 6:59 7:16 
1 1:7 2:52 3:1 4:10 5:2 6:4 
1 2:51 4:6 5:6 6:57 7:21 
1 1:7 3:1 4:10 6:59 7:2 
1 1:7 3:1 4:10 6:1 
1 1:23 2:33 3:1 4:10 5:5 6:10 7:1 
1 2:50 4:1 5:1 6:25 
1 1:7 2:52 4:5 7:23 
1 2:8 4:6 5:6 7:23 
1 1:7 2:52 3:1 4:10 5:3 6:2 7:1 
1 1:7 2:52 4:7 5:2 7:23 
1 1:7 3:1 4:10 6:1 7:23 
1 2:46 4:5 5:2 6:57 
1 1:19 2:33 3:1 4:10 5:6 6:58 7:2 
1 1:7 2:52 4:2 5:6 6:32 
1 1:7 2:52 4:6 6:59 7:22 
1 2:46 4:4 5:2 6:58 
1 1:7 2:52 4:4 6:1 7:23 
1 1:7 3:1 4:10 5:5 6:1 7:23 
1 1:7 2:52 4:7 5:1 6:58 
1 1:7 4:6 5:4 6:59 7:23 
1 1:7 3:1 4:10 6:58 7:22 
1 1:7 3:1 4:10 5:3 6:57 
1 1:19 2:33 3:1 4:10 5:3 6:59 7:22 
1 1:7 3:1 4:11 6:1 
1 1:7 2:52 4:6 5:4 6:59 
1 1:7 2:1 4:6 5:6 6:1 7:1 
1 1:7 4:4 6:1 7:23 
1 1:7 2:52 3:1 4:9 5:1 6:56 
1 1:23 2:33 3:1 4:10 5:5 7:8 
1 1:7 4:2 5:3 6:29 7:23 
1 1:7 2:52 3:1 4:10 5:5 6:57 
1 1:7 2:2 4:7 6:1 
1 1:7 2:1 4:1 6:1 7:22 
1 2:50 4:6 5:2 6:57 
1 1:18 2:33 3:1 4:8 5:6 6:59 7:22 
1 2:50 4:6 5:5 6:3 7:1 
1 1:23 2:33 3:1 4:10 5:1 6:21 
1 1:7 2:52 4:3 5:5 6:58 7:22 
1 1:7 2:1 4:7 5:5 6:59 7:23 
1 1:7 3:1 4:10 7:23 
1 1:7 2:52 4:5 5:5 6:56 
1 1:7 3:1 4:8 5:5 6:59 
1 1:23 2:33 3:1 4:8 5:6 6:54 
1 1:7 2:52 4:6 6:3 
1 1:7 2:52 4:5 6:2 
1 1:23 2:33 3:1 4:10 5:3 6:41 7:22 
1 1:23 2:33 3:1 4:10 5:4 6:13 7:1 
1 1:7 2:1 4:1 6:26 7:23 
1 2:50 4:5 5:6 6:24 7:23 
1 1:7 4:7 6:3 
1 2:8 4:3 5:5 6:59 7:22 
1 1:7 2:52 4:6 5:2 7:23 
1 1:7 3:1 4:10 5:1 6:56 
1 2:46 4:3 5:6 6:1 7:1 
1 2:51 4:7 5:6 6:13 
1 1:7 3:1 4:10 5:6 6:1 7:23 
1 1:7 3:1 4:10 5:1 6:59 7:22 
', '[["Applications", "Book", "Business", "Education", "Entertainment", "Finance", "Food & Drink", "Games", "Graphics & Design", "Health & Fitness", "Lifestyle", "Medical", "Music", "Navigation", "News", "Photo & Video", "Productivity", "Reference", "Shopping", "Social Networking", "Sports", "Stickers", "Travel", "Utilities", "Weather"], ["Action", "Adventure", "Arcade", "Art", "Art & Design", "Auto & Vehicles", "Beauty", "Board", "Books & Reference", "Business", "Card", "Casino", "Casual", "Comics", "Communication", "Dating", "Education", "Educational", "Entertainment", "Events", "Family", "Finance", "Food & Drink", "Games", "Health & Fitness", "House & Home", "Libraries & Demo", "Lifestyle", "Maps & Navigation", "Medical", "Music", "Music & Audio", "News & Magazines", "None", "Parenting", "Personalization", "Photography", "Productivity", "Puzzle", "Racing", "Role Playing", "Shopping", "Simulation", "Social", "Sports", "Strategy", "Tools", "Travel & Local", "Trivia", "Utilities", "Video Players & Editors", "Weather", "Word"], ["android", "ios"], [4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15], [0, 1, 2, 3, 4, 5, 6], [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59], [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23]]','gamecategory,subgamecategory,os,osv,wday,minutes,hours','active');

CREATE TABLE `line_item_channels` (
  `line_item_id` int(10) unsigned NOT NULL,
  `channel_id` int(10) unsigned NOT NULL,
  `type` enum('allow','reject') NOT NULL DEFAULT 'allow',
  PRIMARY KEY (`line_item_id`,`channel_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `line_item_channels` VALUES (2,2,'allow');

