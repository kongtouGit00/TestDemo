t = {
  first = 1,
  second = 2,

  add = function(t, data)
      t.first = t.second + data
  end,

}

mt = {

  __index = function(t, k)
      return 100
  end,

  __newindex = function(t, k, v)
      rawset(t, k, v)
  end
}

setmetatable(t, mt)

print(t.first)
print(t["first"])
print(t.another)

t["third"] = 3
print(t.third)

t.add(t, 10)
print(t.first)
t:add(10)
print(t["first"])

t["forth"] = 4
print(t.forth)
