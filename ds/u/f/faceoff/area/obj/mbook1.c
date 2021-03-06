#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("百草圖鑑", ({ "medicine book","book" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "本");
                set("long", "一本給初學者學習(learn)的藥典。");
        }
        setup();
}

void init()
{
        add_action("do_read","learn");
}

int do_read(string arg)
{
        object me, obj, tar_ob;
        string tar;
        me = this_player();
        obj = this_object();

        if( !arg || sscanf(arg, "from %s", tar)!=1 )
                return notify_fail("請用 learn from <物品> 來學習！\n");
        if( !objectp(tar_ob=present(tar, me)) )
                return notify_fail("你身上沒有這個東西！\n");
        if( tar_ob != this_object() )
                return notify_fail("你不能從這上面學到任何東西！\n");
        if( me->query_skill("regs-knowledge") > 20 )
                return notify_fail(CYN"你已經可以掌握這本書的內容了。\n"NOR);
        if( me->is_fighting() )
                return notify_fail(CYN"在戰鬥中讀書?!..\n"NOR);
        if( sizeof(me->query_temp("is_busy")) )
                 return notify_fail(CYN"你現在正在忙，無法讀書ㄛ..。\n"NOR);
        if( me->query_skill("literate") == 0 )
                return notify_fail(CYN"你還是文盲耶...-_-..。\n"NOR);
        if( me->query_temp("read_book") == 1 )
                return notify_fail(CYN"你已經在讀書了 ...-_-\n"NOR);
        if( me->query("ap") < 11 )
                return notify_fail(CYN"你的體力不夠嚕！\n"NOR);

        message_vision("$N看了看手中百草圖鑑...\n"  ,me);
        obj->set_temp("read_book",1);
        obj->set("no_drop", 1);
        obj->set("no_give", 1);
        obj->set("no_sac", 1);
        call_out("read_book", 1, me, obj, 1);

        return 1;
}

void read_book(object me, object obj, int flag)
{
        if( !me || environment(obj) != me )
        {
                obj->delete("no_drop");
                obj->delete("no_sac");
        }

        if( flag > 1 && me->query("mp") < 21 )
        {
                message_vision(HIR"$N腦中一片混亂，登時站了起來。\n"NOR, me);
                me->delete_temp("read_book");
        }

        if( flag == 1 )
        {
                message_vision(CYN"$N鬆鬆衣帶，就地坐下讀起百草圖鑑。\n"NOR, me);
                me->receive_damage("mp",10); 
                me->start_busy(2);
                call_out("read_book", 3, me, obj, 2);
        }
        else if( flag && flag < 5 && flag > 1 )
        {
                message_vision(CYN"$N正聚精會神的讀著百草圖鑑。\n"NOR, me);
                me->receive_damage("mp",10); 
                me->improve_skill("regs-knowledge",10);
                me->start_busy(2);
                call_out("read_book", 3, me, obj, ++flag);
        }
        else if( flag == 5 )
        {
                message_vision(CYN"$N合起百草圖鑑，默想剛才讀到的新知。\n"NOR, me);
                me->receive_damage("mp",30); 
                me->improve_skill("regs-knowledge",20);
                me->start_busy(2);
                me->delete_temp("read_book");
        }
        else tell_object(me, this_object()->name() + "：錯誤！請通知 Faceoff book 傳遞錯誤！\n");
}

