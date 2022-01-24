#!/usr/bin/env ruby

require_relative '../example'

require_relative 'ex3_simple_logger'
require_relative 'ex4_manual'

example %q{

logger1 = SimpleLogger.instance   # Returns the logger
logger2 = SimpleLogger.instance   # Returns exactly the same logger


SimpleLogger.instance.info('Computer wins chess game.')
SimpleLogger.instance.warning('AE-35 hardware failure predicted.')
SimpleLogger.instance.error(
    'HAL-9000 malfunction, take emergency action!')

}
