from rfc2html import markup
with open('rfc.txt') as file:
    text = file.read()
html = markup(text)
with open('rfc.html', "w") as file:
    file.write(html)