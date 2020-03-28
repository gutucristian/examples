# Mail Merge

For this lab, you are to implement a text based mail-merge utility. 
Mail merge is a simple idea. It takes as input two files. The first 
file is a standard letter template that refers to a number of *placeholder* 
variables. The second file is a comma-separated value file containing a 
list of records. The first row of the CSV file contains the name of the `k` 
columns (separated by commas as well). Each subsequent line is a row of 
the table providing values for the fields. To simplify our task, let's 
assume that no fields contain comma.  

The objective of the mail merge is to produce a collection of `n` files,
one per row in the CSV table that are instantiations of the template.
Indeed, place-holders in the document must be replaced by the
corresponding field (column) of the CSV table row currently processed.
Naturally, we would love to have these fields properly formatted and the
mail-merge program should support *formulas* to layout the fields as
desired. 

## Example

### A mail-merge template

The insert below shows a simple template, data file and one of the outputs
(you should have one output file per row of the CSV).  Note that the output
file uses markdown syntax to produce simple formatting such as boldfacing a
word (use of the double star on either side of the bolded fragment). 

```
Dear $salutation $fName $lName,

It has come to our attention that the invoice numbered $bold(invoice) sent on
$date(when) remains unpaid as of $today(0). If you have already executed the
payment, please disregard this letter. If not, we remind you that the amount
$usd(amout) is past due. We urge you to settle your account as failure to do
so by $today(10) would result in a late penalty of $scale(amount,0.1). 

We look forward to receiving your payment

Sincerely yours,

--
Vultures Inc's law firm.

```

### A CSV Table

```
salutation,lName,fName,address,phone,invoice,amount,when
Dr.,Michel,Laurent,007 Secret street,860-486-2584,04235,12,04/01/2017
Mrs.,Puffet,Valerie,The Restaurant at the End of the Universe,000-000-0000,06932,3612,04/01/2017
```

### Output send to merge_2.txt

```
Dear Mrs. Valerie Puffet,

It has come to our attention that the invoice numbered **06932** sent on
04/01/2017 remains unpaid as of 04/03/2017. If you have already executed the
payment, please disregard this letter. If not, we remind you that the amount
3,612USD is past due. We urge you to settle your account as failure to do so
by 04/13/2017 would result in a late penalty of 361.2USD. 

We look forward to receiving your payment

Sincerely yours,

--
Vultures Inc's law firm.

```

## Syntax
It is clear that the example uses several constructions. 

* $name is the simplest formatting command and is used  to refer to a variable in the CSV. 
* $today(k) is a function taking a positive integer `k` to denote a date `k` days after today. 
* $usd(x) is a function to format a number `x` (which is a variable name from the CSV) as a currency.
* $scale(x,r) is a function that computes the value `x` * `r` and formats the answer as a currency. 
* $date(x) is a function that formats `x` (a field from the CSV) as a date. 

# Objective

Your task is to write a command-line tool that takes as input  the two file
names and produces in the current working directory one text file (extension
.md) per row of the CSV file named `merge_k.md` whose content is the result of
the mail merge.

Think about the code organization as a collection of classes. Organize the
design so that it is  extensible (to support new commands in the future),
clear, clean and elegant. 

# Design Decisions

This is _one_ of the potential design for this problem. There are alternatives 
of course. The objective of the design is to be flexible, generalize quite well
to changing requirements and adopt an OOP methodology for organizing the code.

In particular, _concepts_ in the design give give to _classes_ and _types_ in the 
code. Those are the _bones_ on which one can graft muscles like the _methods_. 


## Representation

### Classes

You need classes for the following:

- The database of those recipients. This is what you get when you read the entire CSV
file. Keep in mind that this is a simple container, e.g., a `list` of Recipients. 
When you read the database, the first row give you the column headers of the CSV file. 
Clearly, the database _has_ a schema and a list of recipients.
- This `list` of field names picked up from your DB is your _schema_ (another class!). 
- The intended Recipients of the letters (aka the _Victims_). Each recipient _has_ a `map`
of field values (one for each name in the _schema_).
- You will need a `template` for the pro-forma letter (with the functions and
variable names). The template _has_ a buffer with the raw text of the letter
template. It also _has_ a `map` that  associates to each field in the schema a
_Responder_ responsible for replacing that field name by its value. The same
`map` associates another kind of _Responder_ responsible for calculating some
function (e.g., `today()`).  This `map` is the **responders table**. 
- Clearly, we have multiple kind of _Responder_. So _Responder_ is an abstract class.
- A concrete version of responder _is_ a fieldResponder.
- Another concrete version of responder _is_ a functionResponder. 

### Responders

To make it clear, a _functionResponder_ should encapsulate a lambda to get the work done. 
That lambda should take 2 inputs:

- a _Recipient_ that will be used as a source of data
- at a minimum a `vector<string>`  (or `vector<Param>` where a `Param` is another class) 
  that holds the values of the arguments being passed to the responder.

  	For instance $date(when) is a _functionResponder_ that should fetch the attribute
  	`when` of the current recipient and format that field as a date to insert the result into
  	the output. So the _functionResponder_ would encapsulate a lambda that takes as input 
  	the current recipient of the letter and a vector of strings ["when"] (or Params). 
- The mailMerge is a method applied on the `template` that takes as input the target `Recipient`
  and produces as output a file named, for instance, **letter_<k>.txt** where <k> is replaced
  by an integer between 0 and n-1 (assuming that the victim DB has `n` records). 
- The mailMerge simply copies the bytes of the source buffer in the input buffer. If the current
  byte is `$`, then it is not copied. Instead, it parses the name of the function and its arguments,
  then looks up in a Responder table for the Responder whose name is the string just read. If it
  finds this Responder, it _invokes_ it passing as input a `vector<string>` with all the 
  collected arguments. The output of the responder (a string) is added into the output stream 
  instead of the command that started with this '$' sign. Processing resumes on the first character
  following the command. Keep going until the entire buffer is transcribed. 

- The schema (a class containing the list of fields)  is used to populate the responder table 
  with entries for all the fields in the victim DB. 




-


