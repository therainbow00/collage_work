#!/usr/bin/env ruby

require 'test/unit'
require 'pp'

require_relative 'ex1_message'
require_relative 'ex2_adapters'
require_relative 'ex4_byname'

class HardcodedChooserTest < Test::Unit::TestCase


  def test_adapter_for_file
    m = Message.new('fred', 'file:///foo/bar', 'message')
    a = adapter_for(m)
    assert_equal FileAdapter, a.class
  end
  
  def test_adapter_for_http
    m = Message.new('fred', 'http://www.yahoo.com:/foo/bar', 'message')
    a = adapter_for(m)
    assert_equal HttpAdapter, a.class
  end
  
  def test_adapter_for_smtp
    m = Message.new('fred', 'smtp:george@acme.com', 'message')
    a = adapter_for(m)
    assert_equal SmtpAdapter, a.class
  end
  
end
