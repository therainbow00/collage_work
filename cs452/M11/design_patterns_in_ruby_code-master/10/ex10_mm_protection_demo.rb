#!/usr/bin/env ruby
require_relative '../example'

require_relative 'ex10_mm_protection'
require_relative 'ex1_account'


example %q{
s = AccountProtectionProxy.new( "a simple string", 'russolsen' )
puts "The length of the string is #{s.length}"
}

expect_error %q{
s = AccountProtectionProxy.new( "a simple string", 'fred' )
puts "The length of the string is #{s.length}"
}
