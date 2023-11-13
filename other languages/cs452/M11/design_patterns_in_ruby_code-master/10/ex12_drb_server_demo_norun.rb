#!/usr/bin/env ruby
require_relative '../example'

example %q{

#
# A service to aid the numerically challenged.
#
class MathService
  def add(a, b)
    return a + b
  end
end

require_relative 'drb/drb'

math_service=MathService.new
DRb.start_service("druby://localhost:3030", math_service)
DRb.thread.join

}
