#include <ansi.h>

inherit NPC;

void create()
{
        set_name("工作人員",({"official"}));
        set("gender", "男性");
        set("long",@LONG
他是政府所請的一位工作人員，負責批發證照的工作。
LONG
        );
        set("level",10);                
        set("age",40);                  
 set("talk_reply","你要申請證照嗎？\n");
        set("inquiry/證照","這裡暫時只提供申請醫生的證照。\n");
  set("inquiry/help",
        HIY"APPLY　　加入醫生工會\n"NOR);
       setup();
}
void init()
{
                add_action("do_apply","apply");
}
int do_apply(string arg)
{
        int i;
        object ob, me, pass;
        ob = this_object();
        me = this_player();
        message_vision("$N想加入「"+ arg+ "」。\n",me); 
        if(!arg || arg!="醫生" )
                return notify_fail("這裡沒有這個公會。\n");
if(me->query_skill("literate")<20) return notify_fail("你不適合做醫生。\n");
if(pass=present("passport of doctor",me)) return notify_fail("你已經有醫生證照了。\n");      
        if(stringp(me->query("class1") ) )
                return notify_fail("你已經參加公會或門派了。\n");
        if(me->query_temp("get_pass") ) return notify_fail("你已經有醫生證照了。\n");
{
        command("nod");
 //       command("say 由現在開始你便是醫生公會的一份子。");
pass=new(__DIR__"obj/doctor_pass"); //開放後請改做/open/always
pass->move(me);
message_vision("工作人員給了$n一本醫生證照。\n");
        me->set_temp("get_pass");
me->set("class1","醫生"); //放這句便不會出現拿pass後入其他門派
        }               
        return 1;
}
