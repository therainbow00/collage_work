#!/usr/bin/env ruby

require 'test/unit'
require 'pp'

require_relative 'ex1_duck'
require_relative 'ex3_frog'
require_relative 'ex4_factory_method'

class FactoryMethodPondTest < Test::Unit::TestCase


  def test_duck_pond
    p = DuckPond.new(1)
    assert_equal Duck, p.instance_variable_get(:@animals)[0].class
    p.simulate_one_day
  end
  
  def test_frog_pond
    p = FrogPond.new(1)
    assert_equal Frog, p.instance_variable_get(:@animals)[0].class
    p.simulate_one_day
  end
  
end
