--create by nimol
SLUI = class("SLUI");

local scheduler = cc.Director:getInstance():getScheduler()--全局定时器
SLUI.getUI=function(filename)end;

 function nexttick(fun)
  local scheshow = nil;
  local function show()
    if scheshow then
      scheduler:unscheduleScriptEntry(scheshow);
    else
      return;
    end
    fun();
  end
  scheshow = scheduler:scheduleScriptFunc(show,0,false);
end

function SLUI:loadUI(fileName)
	assert(fileName, "csb filename is nil")
	return cc.CSLoader:getInstance():createNodeWithFlatBuffersFile(fileName);
end

function SLUI:createNode(filename, callback)
	assert(filename, "csb filename is nil")
	local ret = nil
	if callback then
		ret = cc.CSLoader:createNode(filename, callback);
	else
		ret = cc.CSLoader:createNode(filename);
	end
	return  ret
end

function SLUI:createAini(filename)
	assert(filename, "csb Timeline filename is nil")
	return cc.CSLoader:createTimeline(filename)
end

function SLUI:getChildByName(parent, name)
	--递归查找控件 相当于以前的seekWidgetByName
    local ret = parent:getChildByName(name)
    if ret then
        return ret
    end

    local children = parent:getChildren()
    -- cclog("#children",#children)
    if #children ==0 then
        return nil
    end
    for i=1,#children do
        local child = children[i]
        local tmp = self:getChildByName(child, name)
        if tmp then
            return tmp
        end

    end
end

function SLUI:getUI(filename)
		local tail='.csd';
	    gd_useCsb=true;--强制使用csb
		if gd_useCsb then
			tail='.csb';
		end
		local csname='cocosstudio/' .. filename .. tail;
		if gd_useCsb then
			return cc.CSLoader:getInstance():createNodeWithFlatBuffersFile(csname);
		else
			return cc.CSLoader:getInstance():createNodeWithFlatBuffersForSimulator(csname);
		end
end

function SLUI:bindTextView(textview,listener,opname)
    if textview.sl_listener then
        return textview;--表示已经绑定过了，可加断言
    end
    textview:setTouchEnabled(true)
    assert(listener,"缺少监听对象");
    assert(opname,"缺少操作名");
    textview.sl_listener=listener;
    if gd_devmode=='dev' then
        if not textview.bindtag then
            textview.bindtag=cc.Sprite:create("bindtag.png");
            textview:addChild(textview.bindtag);
            textview.bindtag:setPosition(cc.p(textview:getContentSize().width/2,textview:getContentSize().height/2));
        end
    end
    local function touchcallback(sender,event)
        if event == 2 then
            assert(textview.cb_click,"缺少监听回调")
            --可以再这里做完动画再去执行动作
            userop.userop(opname);
            nexttick(function ( ... )
                textview.cb_click(listener,sender,sender:getName(),sender:getTag());
            end)
        end

    end
    textview:addTouchEventListener(touchcallback);
    return textview;
end
function SLUI:bindBTN(btn,listener,opname, useClickInterface)
	if btn.sl_listener then
		return btn;--表示已经绑定过了，可加断言
	end

	assert(listener,"缺少监听对象");
	assert(opname,"缺少操作名");
	btn.sl_listener=listener;
	btn.sl_opname=opname;
	if gd_devmode=='dev' then
		if not btn.bindtag then
			btn.bindtag=cc.Sprite:create("bindtag.png");
			btn:addChild(btn.bindtag);
			btn.bindtag:setPosition(cc.p(btn:getContentSize().width/2,btn:getContentSize().height/2));
		end
	end

	btn.setState = function(sender, flag) 

		if 1 == flag then 
			--local label = sender:getTitleRenderer();
			local label_title = sender:getChildByName('label_title');

			if label_title then 
				sender.__my_custom_LastTextColor__ = cc.c4b(label_title:getTextColor().r, 
															label_title:getTextColor().g, 
															label_title:getTextColor().b, 
															label_title:getTextColor().g	
														);

				sender.__my_custom_LastTextOutlineColor__ = cc.c4b(label_title:getEffectColor().r, 
																   label_title:getEffectColor().g, 
																   label_title:getEffectColor().b, 
																   label_title:getEffectColor().a	
															   );

				label_title:setTextColor(cc.c4b(0xff, 0xff, 0xff, 0xff));
				label_title:enableOutline(cc.c4b(93, 93, 93, 255), 2);
			end

			sender:setEnabled(false);
		else
			--local label = sender:getTitleRenderer();
			local label_title = sender:getChildByName('label_title');

			if label_title then 
				if sender.__my_custom_LastTextColor__ then 
					label_title:setTextColor(sender.__my_custom_LastTextColor__)
				end

				if sender.__my_custom_LastTextOutlineColor__ then 
					label_title:enableOutline(sender.__my_custom_LastTextOutlineColor__, 2);
				end
			end
			sender:setEnabled(true);
		end

		local vRender = sender:getVirtualRenderer()
		vRender:setState(flag)
	end

	btn:setPressedActionEnabled(true);
	btn:setZoomScale(-0.1);

	local scaleX = btn:getScaleX();
	local scaleY = btn:getScaleY();

	local function buttonClickCallback(sender, type)
	    assert(btn.cb_click,"缺少监听回调")
		--可以再这里做完动画再去执行动作

		if type == cc.EventCode.BEGAN then
			sender:setScaleX(scaleX * 0.92);
			sender:setScaleY(scaleX * 0.92);

		elseif type == cc.EventCode.CANCELLED then
			sender:setScaleX(scaleX);
			sender:setScaleY(scaleY);
		elseif type == cc.EventCode.MOVED then
			--sender:setScale(1);
		elseif type == cc.EventCode.ENDED then
			userop.userop(opname);

			sender:setScaleX(scaleX);
			sender:setScaleY(scaleY);

			if not sender.__my_custom_time_tag__ then 
				nexttick(function ( ... )
					sender.cb_click(listener,sender,sender:getName(),sender:getTag());
				end)

				sender.__my_custom_time_tag__ = os.clock();
			else
				if os.clock() - sender.__my_custom_time_tag__  > 0.4 then 
					nexttick(function ( ... )
						sender.cb_click(listener,sender,sender:getName(),sender:getTag());
					end)

					sender.__my_custom_time_tag__ = os.clock();
				end
			end
		end
	end


	if useClickInterface then 
		btn:addClickEventListener(function(sender) 
			buttonClickCallback(sender, cc.EventCode.ENDED);
		end);
	else
		btn:addTouchEventListener(buttonClickCallback);
	end

	return btn;
end



--进度条方法有限,需要扩展


function SLUI:bindLoadingBar(loadingbar,listener)
	if loadingbar.sl_listener then
		return;--表示已经绑定过了
	end
    assert(listener,"缺失监听对象");
	loadingbar.sl_listener=listener;--进度条总数
	loadingbar.sl_maxvalue=0;--进度条总数
	loadingbar.sl_changecb=nil;--进度条改变回调
	loadingbar.sl_endcb=nil;--进度条慢条回调
	loadingbar.sl_curvalue=0;--进度条当前值
	loadingbar.sl_prevalue=0;--进度条之前的值
	loadingbar.sl_intertime=0;--进度调变化时间间隔
	loadingbar.sl_bprogress=false;--时候走进度条
	loadingbar.sl_processto=0;
	loadingbar.sl_isend=false;
	loadingbar.startProgressFromTo=function(listener,from,to,inter)
		assert(loadingbar.sl_maxvalue>0,"最大值不能为0");
		loadingbar.sl_intertime=inter;
		loadingbar.sl_bprogress=true;
		loadingbar.sl_curvalue=from;
		cclog("to",from,to)
		loadingbar.sl_processto=to;
		loadingbar.sl_isend=false;
		loadingbar.sl_curvalue=from;
		loadingbar.sl_prevalue=from;
		loadingbar:setPercent(loadingbar:getPercentage());
	end
	loadingbar.setValue=function(listener,value)
		loadingbar.sl_curvalue=value;
	end
	loadingbar.setMaxValue=function(listener,maxvalue)
		loadingbar.sl_isend=false;
		loadingbar.sl_maxvalue=maxvalue;
		loadingbar:setPercent(loadingbar:getPercentage());
	end
	loadingbar.setOnProgressEndedListener=function(listener,cb)
		loadingbar.sl_endcb=cb;
	end
	loadingbar.setOnValueChangedListener=function(listener,cb)
		loadingbar.sl_changecb=cb;
	end
	loadingbar.getPercentage=function(listener)
		assert(loadingbar.sl_maxvalue>0,"最大值不能为0")
		return math.floor(loadingbar.sl_curvalue/loadingbar.sl_maxvalue*100);
	end

	local function sfun(dt)

		if loadingbar.sl_prevalue ~= loadingbar.sl_curvalue then
		    loadingbar.sl_prevalue=loadingbar.sl_curvalue;
		    if loadingbar.sl_changecb then
				loadingbar.sl_changecb(loadingbar.sl_listener,loadingbar,loadingbar:getPercentage());
			end
		    loadingbar:setPercent(loadingbar:getPercentage());
	   end
	   if not loadingbar.sl_isend then
			if loadingbar.sl_processto > 0 then
				if loadingbar.sl_curvalue> loadingbar.sl_processto then--这边怕有边界问题
					loadingbar.sl_isend=true;
					loadingbar.sl_bprogress=false;
					if loadingbar.sl_endcb then

						loadingbar.sl_endcb(loadingbar.sl_listener,loadingbar);
					end
				end
			end
	   end
	   --如果进度条在走的话，就开始增长。开始增长
	   if loadingbar.sl_bprogress then
		  loadingbar.sl_curvalue=loadingbar.sl_curvalue+1;
	   end
	end
	loadingbar.schedulerEntry = scheduler:scheduleScriptFunc(sfun,0,false);
	local function onNodeEvent(event)
		if "exit" == event then
			scheduler:unscheduleScriptEntry(loadingbar.schedulerEntry)
			loadingbar.schedulerEntry=nil;
		end
	end
	loadingbar:registerScriptHandler(onNodeEvent);
end

function SLUI:bindImageTouch(img,listener,opname)
	assert(img,"缺少绑定对象");
	assert(listener,"缺少坚挺对象");
	assert(opname,"缺少操作名");
	if img.sl_listener then --重复绑定
		return;
	end
	img.sl_enable=true;
	img.sl_listener=listener;
	img.sl_opname=opname;
	img.ontouchbegancb=nil;
	img.ontouchendedcb=nil;
	img.ontouchmovedcb=nil;
	img.onclickcb=nil;

	if gd_devmode=='dev' then
		if not img.bindtag then
			img.bindtag=cc.Sprite:create("bindtag.png");
			img:addChild(img.bindtag);
			img.bindtag:setPosition(cc.p(img:getContentSize().width/2,img:getContentSize().height/2));
		end
	end
    img.setTouchEnabled=function(listener,enable)
    	cclog("···listener enable ",listener,enable)

    	img.sl_enable=enable;
    end
    
	img.setOnClickListener=function(listener,cb)
		img.onclickcb=cb;
	end
	img.setOnTouchBeganListener=function(listener,cb)
		img.ontouchbegancb=cb;
	end
	img.setOnTouchEndedListener=function(listener,cb)
		img.ontouchendedcb=cb;
	end

	local function onTouchBegan(touch, event)
		if not img.sl_enable then 
			return false;
		end 
        local target = event:getCurrentTarget();
        local locationInNode = target:convertToNodeSpace(touch:getLocation())
        local s = target:getContentSize();
        local rect = cc.rect(0, 0, s.width, s.height);

        if cc.rectContainsPoint(rect, locationInNode) then
            --如果在操作范围内
			if img.ontouchbegancb then
				img.ontouchbegancb(img.sl_listener,img,touch,event)
			end
            return true
        end
        return false
    end
    local function onTouchMoved(touch, event)
		if img.ontouchmovedcb then
			img.ontouchmovedcb(img.sl_listener,img,touch,event)
	    end
    end
    local function onTouchEnded(touch, event)
		userop.userop("图片" .. opname);
		if img.ontouchendedcb then
			img.ontouchendedcb(img.sl_listener,img,touch,event)
	    else
			nexttick(function( )
				if img.onclickcb then
					img.onclickcb(img.sl_listener,img);
				end
			end)
		end
    end
    local listener = cc.EventListenerTouchOneByOne:create()
    listener:setSwallowTouches(true)
    listener:registerScriptHandler(onTouchBegan,cc.Handler.EVENT_TOUCH_BEGAN )
    listener:registerScriptHandler(onTouchMoved,cc.Handler.EVENT_TOUCH_MOVED )
    listener:registerScriptHandler(onTouchEnded,cc.Handler.EVENT_TOUCH_ENDED )
    local eventDispatcher = img:getEventDispatcher()
    eventDispatcher:addEventListenerWithSceneGraphPriority(listener , img)

end
function SLUI:bindTab(listener,callback,opname,...)
	--几个互斥
	assert(listener,"缺少监听对象");
	assert(callback,"缺少监听回调");
	assert(opname,"缺少操作名");
	local btns={...};

	for i = 1,#btns do
		local btn=btns[i];
		btn.sl_listener=listener;
		btn.sl_opname=opname;

		if gd_devmode=='dev' then
			if not btn.bindtag then
				btn.bindtag=cc.Sprite:create("bindtag.png");
				btn:addChild(btn.bindtag);
				btn.bindtag:setPosition(cc.p(btn:getContentSize().width/2,btn:getContentSize().height/2));
			end
		end
		btn:setPressedActionEnabled(true);
		local function buttonClickCallback(sender)
			--可以再这里做完动画再去执行动作
			for j=1,#btns do
				btns[j]:setBright(j ~= i);
			end
			userop.userop("标签" .. opname .. i);
			nexttick(function()
				callback(listener,sender,i,btns);
			end)
		end
		btn:addClickEventListener(buttonClickCallback);
	end
end

function SLUI:selectBtn(btn, sel, selOffset)
	if btn.sel then
		if not sel then
			local pos = cc.pAdd(cc.pMul(selOffset, 1), cc.p(btn:getPosition()))
			btn:setPosition(pos)
		end
	else
		if sel then
			local pos = cc.pAdd(cc.pMul(selOffset, -1), cc.p(btn:getPosition()))
			btn:setPosition(pos)
		end
	end
	btn.sel = sel

	local title = btn:getChildByName("Text_Title")
	if title then
		if sel then
			title:setTextColor(cc.c4b(255, 255, 255, 255))
			title:enableOutline(cc.c4b(4, 62, 101, 255), 2)
		else
			title:setTextColor(cc.c4b(209, 163, 147, 255))
			title:enableOutline(cc.c4b(76, 31, 14, 255), 2)
		end
	end
end

function SLUI:bindTabEx(callback, selIndex, selOffset, opname, ...)
    assert(callback,"缺少监听回调");
    assert(opname,"缺少操作名");
	assert(selIndex, "缺少选中索引")
	assert(selOffset, "缺少默认选中偏移")

    local btns = {...};
    for i = 1, #btns do
        local btn = btns[i];
		if gd_devmode=='dev' then
			if not btn.bindtag then
				btn.bindtag=cc.Sprite:create("bindtag.png");
				btn:addChild(btn.bindtag);
				btn.bindtag:setPosition(cc.p(btn:getContentSize().width/2,btn:getContentSize().height/2));
			end
		end
        btn:setPressedActionEnabled(true);
		btn:setBright(selIndex ~= i);
		btn:setZoomScale(-0.1);
		self:selectBtn(btn, selIndex == i, selOffset)

		btn.sl_opname= "标签"..opname..i;

        local function buttonClickCallback(sender)
            if callback(sender, i, btns) then     --如果返回真则需要切换tab
                for j = 1, #btns do
					btns[j]:setBright(j ~= i);    --非当前设置为false
					self:selectBtn(btns[j], j == i, selOffset)
                end
            end
            userop.userop("标签" .. opname .. i);

        end

        btn:addClickEventListener(buttonClickCallback);
    end
end



function SLUI:udpateImage(img,filename,imgtype)--普通图片传0，plist传1
	local  newimage = nil;
	if imgtype ==1 then
		newimage=cc.Sprite:createWithSpriteFrameName(filename);
	else
	    newimage=cc.Sprite:create(filename);
	end
	local contentsize=newimage:getContentSize();
	img:loadTexture(filenameimgtype);--plist类型
	img:setContentSize(contentsize);
end


function SLUI:bindLayoutTouch(layer,listener,opname)
	assert(layer,"缺少绑定对象");
	assert(listener,"缺少坚挺对象");
	assert(opname,"缺少操作名");
	if layer.sl_listener then --重复绑定
		return;
	end
	layer.sl_listener=listener;
	layer.sl_opname=opname;
	
	local function  click( ... )
		userop.userop("面板" .. opname);
    	nexttick(function()
    		if layer.cb_click then 
    			layer.cb_click(layer.sl_listener,layer);
    		end
   	 end)

	end
    layer:addClickEventListener(click);
    return layer;
end

---------add by lx---------------
function SLUI:labelSemplifyNumSetString(lable, count)
	assert(lable,"缺少绑定对象");
	count = count or 0;
	if count > 999999 then
		count = math.floor(count / 1000);
		count = count / 10;
		lable:setString(count .. '万');
	else
		lable:setString(count .. '');
	end
end
function SLUI:createOneTimesEffect(effectname,startframe,endframe,isremoved, evt_func) 
   evt_func = evt_func or function ()end; 
	local csbname="cocosstudio/effects/" .. effectname .. ".csb";
	local csbnode = cc.CSLoader:createNode(csbname);
	local action = cc.CSLoader:createTimeline(csbname);
    action:gotoFrameAndPlay(startframe, endframe, false); 
    csbnode:runAction(action);
    local function callback(frame) 
    cclog("SLUI:createOneTimesEffect----------------------");
        if isremoved then 
            csbnode:removeFromParent();
        end 
        local evt=nil;
        if frame then 
        	evt = frame:getEvent()
        end 
    	evt_func(frame,evt); 
    end
    action:setFrameEventCallFunc(callback);
    return csbnode;
end

function SLUI:createForeverEffectWithName(effectname) 
	local csbname="cocosstudio/effects/" .. effectname .. ".csb";
	local csbnode = cc.CSLoader:createNode(csbname);
	local action = cc.CSLoader:createTimeline(csbname);
    action:gotoFrameAndPlay(0, true); 
    csbnode:runAction(action); 
    return csbnode;
end 

function SLUI:createForeverEffect(effectname,startframe,endframe) 
   evt_func = evt_func or function ()end; 
	local csbname="cocosstudio/effects/" .. effectname .. ".csb";
	local csbnode = cc.CSLoader:createNode(csbname);
	local action = cc.CSLoader:createTimeline(csbname);
    action:gotoFrameAndPlay(startframe, endframe, true); 
    csbnode:runAction(action); 
    return csbnode;
end 

function SLUI:createEffectWithEvent(effectname,startframe,endframe,isRepeate,event_cb) 
	assert(event == nil or type(event_cb) == "table" ,"event_cb type Error,expect a table")

	isRepeate = isRepeate or false
   	event_cb = event_cb or {}; 
	local csbname="cocosstudio/effects/" .. effectname .. ".csb";
	local csbnode = cc.CSLoader:createNode(csbname);
	local action = cc.CSLoader:createTimeline(csbname);
    action:gotoFrameAndPlay(startframe, endframe, isRepeate); 
    csbnode:runAction(action);
    local function callback(frame) 
    	-- cclog("SLUI:createEffectWithEvent----------------------");
        local evt=nil;
        if frame then 
        	evt = frame:getEvent()
        end 
        if evt and event_cb[evt] then
        	cclog("Evt,",evt)
        	event_cb[evt](frame,evt)
        end
    end
    action:setFrameEventCallFunc(callback);
    return csbnode;
end

function SLUI:createEffectPathWithEvent(effectfilePath,startframe,endframe,isRepeate,event_cb) 
	isRepeate = isRepeate or false
   	event_cb = event_cb or {}; 
	local csbname=effectfilePath;
	local csbnode = cc.CSLoader:createNode(csbname);
	local action = cc.CSLoader:createTimeline(csbname);
    action:gotoFrameAndPlay(startframe, endframe, isRepeate); 
    csbnode:runAction(action);
    local function callback(frame) 
    	cclog("SLUI:createEffectPathWithEvent----------------------");
        local evt=nil;
        if frame then 
        	evt = frame:getEvent()
        end 
        if evt and event_cb[evt] then
        	event_cb[evt](frame,evt)
        end
    end
    action:setFrameEventCallFunc(callback);
    return csbnode;
end