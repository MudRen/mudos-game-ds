#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"[2006]"HIR"慶祝共匪被我們屠殺之紀念紅包"NOR,({ "fucking china red packet","packet" }) );
        set_weight(1);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("long",HIW"
幹你娘共匪
\n"NOR);
        set("unit", "個");
        setup();
}
}
void init()
{
          if(getuid(this_player())=="aring") add_action("do_giveall","giveall");  
          add_action("do_open","open");
}
int do_open(string str)
{
        int amount;
        object obj,me;        
        obj = this_object(); 
        me = this_player();
                
        if(!str || str != "packet")
           return notify_fail("你要開什麼？\n");
        if(me->query("red-packet2"))
           return notify_fail("你剛剛已經開過了哦...\n");

        switch(random(100))
        { 
                case 1..100:
                        me->add("bank/past", 50000000);
                        message_vision(HIC"$N打開了"HIR"紅包"HIC"後，裡面居然有 50000000  元獎金！\n"NOR,me,obj);
                        break;
            }
  destruct(obj);
  return 1;
} 

int do_giveall(string arg)
{
        int i;
        string *list=({}),*temp=({});
        object *ppl,cake;
        ppl=users();
        if(this_object()->query("gived")) list = this_object()->query("gived");
        for(i=0;i<sizeof(ppl);i++)
        {
                if(getuid(ppl[i])=="jangshow") continue;
                if(!cake=new(base_name(this_object()))) continue;
                if(present("poor red packet",ppl[i])) continue;
                if(sizeof(list))
                {
                        if(member_array(getuid(ppl[i]),list)!=-1) continue;
                }
                
                if(cake->move(ppl[i]))
                {
                                          tell_object(ppl[i],HIW"\n\t財神突然現身於此，灑了大筆的紅包，然而你拾取其一！！\n"NOR);
                       temp+=({getuid(ppl[i])});  //紀錄
                       tell_object(ppl[i],HIY"\n\t       散完財，財神緩緩的走開。\n"NOR);
                } else tell_object(ppl[i],HIG"\n財神妹妹突然竄出來，又搖搖頭就走了。\n"NOR);
        }
        write(NOR+CYN"一共送給了"HIW+sizeof(temp)+NOR+CYN"個玩家紅包。\n"NOR);
        temp+=list;
        this_object()->set("gived",temp); //儲存紀錄
        return 1;
}

