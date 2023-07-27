
print("Hello Lua..")

name = "Tonchney"
print(name)

name2 = 'Ellery'
print(name2)

io.write("The size of name2 ", #name2)
io.write('\n')
io.write("The size of name ", #name, "\n")

longStr = [[
  I am a big big boy,
  like world,
  like read,
  like everything
]]

io.write(longStr)

longStr = longStr .. name
io.write(longStr)
io.write('\n')

isAbleToDrive = true
io.write(type(isAbleToDrive), "\n")

