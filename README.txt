Nodes in block
--------------
Requires Drupal 7, block module, nodeblock module and blockcss module.

Author: Tyler Hullinger - http://drupal.org/user/1993698

Overview:
--------
BlockCT (Block Content Type) utilizes the modules nodesinblock and blockcss to create a content type of block which allows users to manage blocks from within that content type. This is very useful if you are creating a site for someone you do not want to touch the actual block settings in the admin menu.

Installation:
-------------
1. Place this module directory in your modules folder 
   (this will usually be "sites/all/modules/").
2. Go to "administer -> build -> modules" and enable the module.

Configuration:
--------------
Go to "administer -> structure -> BlockCT" 

Allows for you to specify different styles that are applied to the block. This will end up being theme specific and I plan to allow certain class styles available per theme in the future.

Issues:
-------
Nodeblock version 7.x-1.2 has issues when having an admin theme different from the default theme. You have to manually patch nodeblock in order to fix this.

See this issue: http://drupal.org/node/1759196

Support:
--------
Please post all issues and feature requests on github.
https://github.com/tyhullinger/BlockCT

Last updated:
------------
; Monday August 25th 2012 at 10:51AM CST 
