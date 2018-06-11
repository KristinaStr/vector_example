#include <catch.hpp>
#include <sstream>

#include "vector.hpp"

TEST_CASE("creating queue")
{
	queue_t<int> queue;
	REQUIRE( queue.heado() == nullptr );
	REQUIRE( queue.tailo() == nullptr );
}

TEST_CASE("copy queue")
{
	queue_t<int> queue;
	queue_t<int> queue2;
	queue.push(3);
	queue.push(6);
	
	queue2.push(1);
	
	queue2 = queue;
	
	REQUIRE( queue2.headl(queue2.heado()) == 3 );
	REQUIRE( queue2.taill(queue2.tailo()) == 6 );
}

TEST_CASE("pushing elements int")
{
	queue_t <int> queue;

	queue.push(1);
	REQUIRE( queue.headl(queue.heado()) == 1 );
	REQUIRE( queue.taill(queue.tailo()) == 1 );

	queue.push(2);
	REQUIRE( queue.headl(queue.heado()) == 1 );
	REQUIRE( queue.taill(queue.tailo()) == 2 );

	queue.push(3);
	REQUIRE( queue.headl(queue.heado()) == 1 );
	REQUIRE( queue.taill(queue.tailo()) == 3 );
}

TEST_CASE("pushing elements double")
{
	queue_t <double> queue;

	queue.push(1);
	REQUIRE( queue.headl(queue.heado()) == 1 );
	REQUIRE( queue.taill(queue.tailo()) == 1 );

	queue.push(2);
	REQUIRE( queue.headl(queue.heado()) == 1 );
	REQUIRE( queue.taill(queue.tailo()) == 2 );

	queue.push(3);
	REQUIRE( queue.headl(queue.heado()) == 1 );
	REQUIRE( queue.taill(queue.tailo()) == 3 );
}

TEST_CASE("poping elements int")
{
	queue_t <int> queue;

	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);

	queue.pop();
	REQUIRE( queue.headl(queue.head_r()) == 2 );
	REQUIRE( queue.taill(queue.tail_r()) == 4 );

	queue.pop();
	REQUIRE( queue.headl(queue.head_r()) == 3 );
	REQUIRE( queue.taill(queue.tail_r()) == 4 );

	queue.pop();
	REQUIRE( queue.headl(queue.head_r()) == 4 );
	REQUIRE( queue.taill(queue.tail_r()) == 4 );
}

TEST_CASE("poping elements double")
{
	queue_t <double> queue;

	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);

	queue.pop();
	REQUIRE( queue.headl(queue.head_r()) == 2 );
	REQUIRE( queue.taill(queue.tail_r()) == 4 );

	queue.pop();
	REQUIRE( queue.headl(queue.head_r()) == 3 );
	REQUIRE( queue.taill(queue.tail_r()) == 4 );

	queue.pop();
	REQUIRE( queue.headl(queue.head_r()) == 4 );
	REQUIRE( queue.taill(queue.tail_r()) == 4 );
}

TEST_CASE("Error")
{
	queue_t<int> queue;
	REQUIRE_THROWS_AS( queue.pop() , std::logic_error);
}
