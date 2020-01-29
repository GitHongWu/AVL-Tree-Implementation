/*test.cpp*/

//
// Lab week 07:
// 
// AVL unit tests based on Catch framework.  We are assuming the AVL class is now
// balancing the trees in these tests.
//

#include <iostream>
#include <vector>

#include "avl.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

TEST_CASE("(1) AVL tree with 4 nodes") 
{
  avltree<int, int>  avl;

  //
  // build a simple BST tree with 4 nodes:
  //
  avl.insert(100, -100);
  avl.insert(50, -50);
  avl.insert(150, -150);
  avl.insert(125, -125);

  // 
  // Tests:
  //
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

  REQUIRE(avl.size() == 4);
  REQUIRE(avl.height() == 2);

  REQUIRE(keys[0] == 50);
  REQUIRE(values[0] == -50);
  REQUIRE(heights[0] == 0);

  REQUIRE(keys[1] == 100);
  REQUIRE(values[1] == -100);
  REQUIRE(heights[1] == 2);

  REQUIRE(keys[2] == 125);
  REQUIRE(values[2] == -125);
  REQUIRE(heights[2] == 0);

  REQUIRE(keys[3] == 150);
  REQUIRE(values[3] == -150);
  REQUIRE(heights[3] == 1);
}

TEST_CASE("(2) empty tree") 
{
  avltree<int, int>  avl;
	
	vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

  REQUIRE(avl.size() == 0);
  REQUIRE(avl.height() == -1);
	REQUIRE(keys.size() == 0);
  REQUIRE(heights.size() == 0);
  REQUIRE(values.size() == 0);
}

TEST_CASE("(3) just one node") 
{
  avltree<int, int>  avl;
	
	avl.insert(123, 88);

  REQUIRE(avl.size() == 1);
  REQUIRE(avl.height() == 0);
	
	vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

	REQUIRE(keys[0] == 123);
	REQUIRE(values[0] == 88);
  REQUIRE(heights[0] == 0);
	
	REQUIRE(keys.size() == 1);
  REQUIRE(heights.size() == 1);
  REQUIRE(values.size() == 1);
}


TEST_CASE("(4) AVL tree insert sorted key") 
{
  avltree<int, int>  avl;
	
  avl.insert(50, 1);
	avl.insert(100, 2);
	avl.insert(125, 3);
  avl.insert(150, 4);

  vector<int>  keys, values, heights;
  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();
	
	REQUIRE(avl.size() == 4);
  REQUIRE(avl.height() == 2);
	REQUIRE(keys.size() == 4);
  REQUIRE(heights.size() == 4);
  REQUIRE(values.size() == 4);
	
	REQUIRE(keys[0] == 50);
  REQUIRE(heights[0] == 0);
  REQUIRE(values[0] == 1);
	
	REQUIRE(keys[1] == 100);
  REQUIRE(heights[1] == 2);
  REQUIRE(values[1] == 2);
	
	REQUIRE(keys[2] == 125);
  REQUIRE(heights[2] == 1);
  REQUIRE(values[2] == 3);
	
	REQUIRE(keys[3] == 150);
  REQUIRE(heights[3] == 0);
  REQUIRE(values[3] == 4);
	
}

TEST_CASE("(5) AVL tree insert duplicate node with same value") 
{
  avltree<int, int>  avl;
	
  avl.insert(100, -100);
  avl.insert(50, -50);
  avl.insert(150, -150);
  avl.insert(125, -125);
	avl.insert(125, 999);
	
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

  REQUIRE(avl.size() == 4);
  REQUIRE(avl.height() == 2);
	
	REQUIRE(keys[0] == 50);
  REQUIRE(heights[0] == 0);
	REQUIRE(values[0] == -50);
	
  REQUIRE(keys[1] == 100);
  REQUIRE(heights[1] == 2);
  REQUIRE(values[1] == -100);
	
  REQUIRE(keys[2] == 125);
  REQUIRE(heights[2] == 0);
  REQUIRE(values[2] == -125);

  REQUIRE(keys[3] == 150);
  REQUIRE(heights[3] == 1);
  REQUIRE(values[3] == -150);
}

TEST_CASE("(6) Left Left Rotate case") 
{
	avltree<int, int>  avl;
	
  avl.insert(7, -7);
	avl.insert(8, -8);
  avl.insert(5, -5);
  avl.insert(3, -3);
  avl.insert(6, -6);
	avl.insert(2, -2);
	avl.insert(4, -4);
	
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();
	
	REQUIRE(avl.size() == 7);
  REQUIRE(avl.height() == 2);
	
	for(int i = 0; i < avl.size(); i++){
		REQUIRE(keys[i] == i + 2);
		REQUIRE(values[i] == -(i + 2) );
		if(i%2 == 0)
			REQUIRE(heights[i] == 0);
	}
	
  REQUIRE(heights[1] == 1);
	REQUIRE(heights[3] == 2);
	REQUIRE(heights[5] == 1);
}

TEST_CASE("(7) Left Right Rotate case") 
{
	avltree<int, int>  avl;
	
  avl.insert(7, -7);
	avl.insert(8, -8);
  avl.insert(3, -3);
  avl.insert(5, -5);
	avl.insert(2, -2);
	avl.insert(4, -4);
	avl.insert(6, -6);
	
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();
	
	REQUIRE(avl.size() == 7);
  REQUIRE(avl.height() == 2);
	
	for(int i = 0; i < avl.size(); i++){
		REQUIRE(keys[i] == i + 2);
		REQUIRE(values[i] == -(i + 2) );
		if(i%2 == 0)
			REQUIRE(heights[i] == 0);
	}

  REQUIRE(heights[1] == 1);
	REQUIRE(heights[3] == 2);
	REQUIRE(heights[5] == 1);
}

TEST_CASE("(8) Right Right Rotate case") 
{
	avltree<int, int>  avl;
	
  avl.insert(3, -3);
	avl.insert(2, -2);
  avl.insert(5, -5);
	avl.insert(4, -4);
	avl.insert(7, -7);
	avl.insert(6, -6);
	avl.insert(8, -8);
	
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();
	
	REQUIRE(avl.size() == 7);
  REQUIRE(avl.height() == 2);
	
	for(int i = 0; i < avl.size(); i++){
		REQUIRE(keys[i] == i + 2);
		REQUIRE(values[i] == -(i + 2) );
		if(i%2 == 0)
			REQUIRE(heights[i] == 0);
	}
	
  REQUIRE(heights[1] == 1);
	REQUIRE(heights[3] == 2);
	REQUIRE(heights[5] == 1);
}

TEST_CASE("(9) Right Left Rotate case") 
{
	avltree<int, int>  avl;
	
  avl.insert(3, -3);
	avl.insert(2, -2);
	avl.insert(7, -7);
  avl.insert(5, -5);
	avl.insert(8, -8);
	avl.insert(4, -4);
	avl.insert(6, -6);
	
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();
	
	REQUIRE(avl.size() == 7);
  REQUIRE(avl.height() == 2);
	
	for(int i = 0; i < avl.size(); i++){
		REQUIRE(keys[i] == i + 2);
		REQUIRE(values[i] == -(i + 2) );
		if(i%2 == 0)
			REQUIRE(heights[i] == 0);
	}
	
  REQUIRE(heights[1] == 1);
	REQUIRE(heights[3] == 2);
	REQUIRE(heights[5] == 1);
}

TEST_CASE("(10) rotate root") 
{
	avltree<int, int>  avl;
	avl.insert(3, -3);
  avl.insert(2, -2);
	avl.insert(1, -1);
	
	vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();
	
	REQUIRE(avl.size() == 3);
  REQUIRE(avl.height() == 1);

	for(int i = 0; i < avl.size(); i++){
		REQUIRE(keys[i] == i + 1);
		REQUIRE(values[i] == -(i + 1) );
	}
	REQUIRE(heights[0] == 0);
	REQUIRE(heights[1] == 1);
	REQUIRE(heights[2] == 0);
}

TEST_CASE("(11) under root Left Left case") 
{
	avltree<int, int>  avl;
	
	avl.insert(7, -7);
  avl.insert(5, -5);
	avl.insert(9, -9);
	avl.insert(3, -3);
	avl.insert(6, -6);
	avl.insert(8, -8);
	avl.insert(10, -10);
	avl.insert(2, -2);
	avl.insert(4, -4);
	avl.insert(1, -1);
	
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();
	
	REQUIRE(avl.size() == 10);
  REQUIRE(avl.height() == 3);
	
	for(int i = 0; i < avl.size(); i++){
		REQUIRE(keys[i] == i + 1);
		REQUIRE(values[i] == -(i + 1) );
	}
	
  REQUIRE(heights[0] == 0);
	REQUIRE(heights[1] == 1);
	REQUIRE(heights[2] == 2);
	REQUIRE(heights[3] == 0);
	REQUIRE(heights[4] == 1);
	REQUIRE(heights[5] == 0);
	REQUIRE(heights[6] == 3);
	REQUIRE(heights[7] == 0);
	REQUIRE(heights[8] == 1);
	REQUIRE(heights[9] == 0);
}

TEST_CASE("(12) under root Left Right case") 
{
	avltree<int, int>  avl;
	avl.insert(7, -7);
  avl.insert(5, -5);
	avl.insert(9, -9);
	avl.insert(2, -2);
	avl.insert(6, -6);
	avl.insert(8, -8);
	avl.insert(10, -10);
	avl.insert(1, -1);
	avl.insert(4, -4);
	avl.insert(3, -3);
	
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();
	
	REQUIRE(avl.size() == 10);
  REQUIRE(avl.height() == 3);
	
	for(int i = 0; i < avl.size(); i++){
		REQUIRE(keys[i] == i + 1);
		REQUIRE(values[i] == -(i + 1) );
	}
	REQUIRE(heights[0] == 0);
	REQUIRE(heights[1] == 1);
	REQUIRE(heights[2] == 0);
	REQUIRE(heights[3] == 2);
	REQUIRE(heights[4] == 1);
	REQUIRE(heights[5] == 0);
	REQUIRE(heights[6] == 3);
	REQUIRE(heights[7] == 0);
	REQUIRE(heights[8] == 1);
	REQUIRE(heights[9] == 0);
}

TEST_CASE("(13) under root Right Right case") 
{
	avltree<int, int>  avl;
	
	avl.insert(4, -4);
	avl.insert(2, -2);
	avl.insert(6, -6);
	avl.insert(1, -1);
	avl.insert(3, -3);
  avl.insert(5, -5);
	avl.insert(8, -8);
	avl.insert(7, -7);
	avl.insert(9, -9);
	avl.insert(10, -10);
	
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();
	
	REQUIRE(avl.size() == 10);
  REQUIRE(avl.height() == 3);
	
	for(int i = 0; i < avl.size(); i++){
		REQUIRE(keys[i] == i + 1);
		REQUIRE(values[i] == -(i + 1) );
	}
	REQUIRE(heights[0] == 0);
	REQUIRE(heights[1] == 1);
	REQUIRE(heights[2] == 0);
	REQUIRE(heights[3] == 3);
	REQUIRE(heights[4] == 0);
	REQUIRE(heights[5] == 1);
	REQUIRE(heights[6] == 0);
	REQUIRE(heights[7] == 2);
	REQUIRE(heights[8] == 1);
	REQUIRE(heights[9] == 0);
}

