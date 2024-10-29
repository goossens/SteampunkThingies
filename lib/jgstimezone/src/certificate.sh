#!/bin/bash

openssl s_client -showcerts -verify 5 -connect ipapi.co:443 < /dev/null |
	awk '/BEGIN CERTIFICATE/,/END CERTIFICATE/{ if(/BEGIN CERTIFICATE/){a++}; out="cert"a".pem"; print >out}'

for cert in *.pem
do
	newname=$(openssl x509 -noout -subject -in $cert | sed -nE 's/.*CN ?= ?(.*)/\1/; s/[ ,.*]/_/g; s/__/_/g; s/_-_/-/; s/^_//g;p' | tr '[:upper:]' '[:lower:]').pem
	mv "${cert}" "${newname}"
done
