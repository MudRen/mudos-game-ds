// 限制 mob 的行動, 以免玩家用神令符來 hest 重要的 mob (例如把關的青眼白龍 or 真紅眼黑龍)
// wilfred@DS
// note by alick,hest的checking應該放回神行令裡~!
// 可以寫個不能Hest的清單在該item裡

inherit ITEM;
void create()
{
  set_name("限制行動",({"notgo"}));
  set_weight(10);
set("no_sac", 1);
set("no_get", 1);
set("no_drop", 1);
set("no_give", 1);
// add no sac,drop,get by alick, invis了的item一樣能Drop,get! by alick
  setup();
  set_temp("invis",1);
}

void init()
{
if( environment(this_object())->is_room()  ) 
{
	destruct(this_object());
	return;
}
// add by alick for fix bug
    /* bug , 胡亂搞... fixed by -Acme- */
    if( !userp(this_player()) ) add_action("action","",1);
}

int action()
{
if( !userp(this_player()) ) 
{
// add by -alick for fix bug
  message_vision("\n$N好像不為所動 ....... \n\n",this_player());
  return 1;
}
}
