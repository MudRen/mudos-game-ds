// This is a room made by roommaker.

#include <ansi.h> 
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�P��");
        set("long", "�@�Ӭ۷������b���P�ǡA����ն��B�@�I�]�夣�X��i����^�C\n");
        set("exits", ([
            "west" : __DIR__"inn_2f",
            "east" : __DIR__"big2room2",
        ]));
        set("objects", ([
            "/obj/big2.c" : 1,
         ]));
        set("light",1);
        setup();
        replace_program(ROOM);
} 
void init()
{
        add_action("do_transfer", "transfer");
}

int do_transfer(string arg)

{
        string from, usr;
        int amount;
        object from_ob, me, usr_ob;

        me = this_player();
        if( !arg || sscanf(arg, "%d %s to %s", amount, from, usr)!=3 )
                return notify_fail("���O�榡�Rtransfer <�ƶq> coin to <���a>\n");
        usr_ob = LOGIN_D->find_body(usr);
        if( !usr_ob ) return notify_fail("�S���o�ӨϥΪ�\n");                
        from_ob = new("obj/money/"+from);
        if( !from_ob ) return notify_fail("�S���o�ؿ�\n");
        if( amount < 1 ) return notify_fail("�@���ֶ̤פ@�ӳf���C\n");
        if( me->query("bank/past"+from) < amount) return notify_fail("�A�Ȧ�̨S���o��h��\n");
        tell_object(me, "�A�N "+HIY+amount+NOR+" "+from_ob->query("base_unit")+from_ob->query("name")+"�׵�"+usr_ob->query("name")+"\n");
        tell_object(usr_ob,HIW"�i"HIG"��"NOR+GRN"��"HIG"�q"NOR+GRN"��"HIW"�j"NOR+me->query("name")+"�׵��A "+HIY+amount+NOR+" "+from_ob->query("base_unit")+from_ob->query("name")+"\n");
        if( me->query("bank/past"+from) == amount ) me->delete("bank/"+from); 
        else me->add("bank/past"+from, -amount);
        usr_ob->add("bank/past"+from, amount);
        return 1;

}

