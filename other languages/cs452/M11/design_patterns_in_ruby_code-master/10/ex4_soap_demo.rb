#!/usr/bin/env ruby
require_relative '../example'

puts "This demo does not work in 2013"

## require_relative 'yaml'
## 
## example %q{
## require 'soap/wsdlDriver'
## 
## wsdl_url = 'http://www.webservicex.net/WeatherForecast.asmx?WSDL'
## 
## proxy = SOAP::WSDLDriverFactory.new( wsdl_url ).create_rpc_driver
## weather_info = proxy.GetWeatherByZipCode('ZipCode'=>'19128')
## 
## }
