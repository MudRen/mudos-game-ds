#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIR"龍戰士"NOR, ({ "dragon knight","knight","dragon" }) );
        set("level", 30); 
        set("title",HIW"東"HIY"龍"HIC"守衛 IIII"NOR);        set("race","人類");
        set("gender","男性");
        set("age",400);
        set_skill("parry", 60);
        set_skill("unarmed", 60);
        set_skill("dodge", 60); 
        add("addition_armor",200);
        add("addition_damage",180);  
        set("long","它是磐龍城禁地的守衛，保護著傳說中的寶物。\n");          setup(); 
 carry_object(__DIR__"obj/sword")->wield();}
void init()
{
        object ob;
        ::init();
        add_action("do_guard", "go");
        if(!this_object()->visible(this_player())) return;
        call_out("greeting", 1, ob);
}
int do_guard(string arg)
{
       if( (arg!= "west") || !this_player()->visible(this_object()) ) return 0;
       write( name() + "張開手臂將你擋了下來。\n");
       command("peer");
       command("say 想過的話 . . . 先過了我這關吧 !");
       return 1;
}
void die()
{
        int i;
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( !ob ) 
        {
                ::die();
                return;
        } 
      message_vision( "$N"+HIG"死前放出最後一股真氣傳向西方，並往西方大喊"+HIW":我把我最後的力量給你，千萬要守好 ! . . "NOR ,this_object() ); 
        ::die();
        return;
}

