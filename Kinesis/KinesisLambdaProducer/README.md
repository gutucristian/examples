 To invoke lambda function asynchronously using aws cli:
 
 `aws lambda invoke --profile saml --region us-east-1 --function-name cg-java-kpl-example --invocation-type Event --payload '{ "data": "abc123" }'`