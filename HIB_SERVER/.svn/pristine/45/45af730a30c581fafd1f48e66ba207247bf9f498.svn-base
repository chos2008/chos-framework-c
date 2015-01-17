print "hello, world"
print("hello, world")

function lua_version()
    print("[LUA] this is lua runtime environment")
end

function lua_onEvent(event)
    print("on event ", event)
    if event == "Click" then 
	print("Click")
    elseif event == "DoubleClick" then
	print("DoubleClick")
    elseif event == "Move" then 
	print("Move")
    end
end

lua_version()

print("register event handler lua_onEvent")
registerEventHandler("lua_onEvent")