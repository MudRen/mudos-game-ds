inherit F_AUTOLOAD;
inherit F_CLEAN_UP;
inherit F_SAVE;
inherit COMBINED_ITEM;     
void create()
{
set_name("[1;32m��Ħ�Ĥ�[0m",({"green potion","potion"}));
set_weight(1250);
 set("value",1400);
set_amount(1);
set("amount",1);
if(!restore())
{
set("unit","�~");
set("long","�Ѻ�Ħ���ҦӦ����Ĥ�, �i�H���t��_�ͩR�O�P��O.\n");
set("kind","hp");
set("usage","��_���a1000�I���ͩR�O�P500�I����O");
set("cure",1000);
}
}


void init()
{
add_action("drink_potion","drink");
}

int drink_potion(string arg)
{
int num
;
object ob,me;
me=this_player();
num = query_amount();            
if(!this_player()) return 0;
if(!arg)
return 0;
if(this_player()->query("hp")<0)
return 0;
if(this_player()->query_temp("supply"))
return notify_fail("�A���b��,�S�ų��Ĥ�\n");
if(arg=="potion")
{
if(this_player()->query("birthday"))
this_player()->add_temp("cmds",1);
if(!ob=present(arg,this_player()))        
return notify_fail("�A�n�ܤ���??\n");
if(ob->query_amount()<1)
return notify_fail("�A�w�g�ܧ��F\n");
if(me->query("hp")>=me->query("max_hp") && me->query("ap")>=me->query("max_ap"))
{
write("�A�ͩR�O�M��O�����F!\n");
return 1;
}
me->add("hp",1000);
me->add("ap",500);
if(me->query("hp")+1000>me->query("max_hp"))
me->set("hp",me->query("max_hp"));
if(me->query("ap")+500>me->query("max_ap"))
me->set("ap",me->query("max_ap"));
message_vision("\n$N�ܤF�@�~[1;32m��Ħ�Ĥ�[m.\n",me);
me->start_busy(1);
num--;
if(num>0)
{ 
set_weight(this_object()->query_weight()-1000);
//me->set_encumbrance(me->query_encumbrance()-1000);
set_amount(num);
} else destruct(this_object());
return 1;
}
}

