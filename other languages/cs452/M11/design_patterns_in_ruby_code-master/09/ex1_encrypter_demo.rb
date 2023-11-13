#!/usr/bin/env ruby

require_relative '../example'

require_relative 'ex1_encrypter'

example %q{
reader = File.open('message.txt')
writer = File.open('message.encrypted','w')
encrypter = Encrypter.new('my secret key')
encrypter.encrypt(reader, writer)


writer.close
}

