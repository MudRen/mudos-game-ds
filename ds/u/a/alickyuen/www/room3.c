/*-----------����/d/wiz/hall_area.c�ק�-----------*/
#include <ansi.h>

string query_ips(object *all_ppl, object current_ppl);
inherit ROOM;
 
void create()
{
    set("short", HIW+BLK"���հ�"NOR);
    set("long",
WHT"\n�i�i�i�i�i"NOR+RED"�i�i�i�i�i"YEL"�i�i�i�i�i"BLU"�i�i�i�i�i\n"
HIW"�i�i�i�i�i"HIR"�i�i�i�i�i"HIY"�i�i�i�i�i"HIB"�i�i�i�i�i\n"
BLK"�i�i�i�i�i"HIM"�i�i�i�i�i"HIG"�i�i�i�i�i"HIC"�i�i�i�i�i\n"NOR);
    set("light",1);               
    set("no_clean_up", 0);
    set("exits", ([
        "up"     : __DIR__"workroom"]));
    set("objects", ([
                "/u/f/fedex/fantasyland/obj/obj1" : 1,
]));
    set("valid_startroom", 1);
    setup();
}

void init()
{
    object me;
    me = this_player();

    if(!userp(me)) return;
    if(!this_object()->query("open") && me->query("id") != "fedex")
    {
       message_vision("\n\n"HIY+me->query("name")+HIM",�ثe�o�Ӧa��L�k�i�J�C\n\n"NOR,me);
       me->move(__DIR__"workroom");
    }
    else
    {
       add_action("do_lock","on");
       add_action("do_unlock","off");
       call_out("welcome",1,me);
    }
    return;
}

int welcome(object me)
{
    int player,wiz;

    foreach(object user in users())
    {
       if(wizardp(user))
       { wiz++; } 
       else if(userp(user) && environment(user))
       { player++; }
    }
    message_vision(HIY+me->query("name")+HIM",�w��^�ӡC\n"NOR,me);
    write(HIM"�ثe�u�W��: ���a"+player+"�H �Ův"+wiz+"�H\n"NOR);

    if(this_object()->query("open"))
    { write(HIW+BLK"[�ϳ��w����]\n"NOR,me); }
    else
    { write(HIW+BLK"[�ϳ��w�Ұ�]\n"NOR,me); }
    return 1;
}

int do_unlock(string arg)
{
    if(this_object()->query("open"))
       return notify_fail("�Ův�L�o�O���w�g�����F�C\n");
    message_vision(HIW"$N�����F�Ův�L�o�˸m�ϤO��!!\n\n"NOR, this_player());
    this_object()->set("open",1);
    return 1;
}

int do_lock(string arg)
{
    object *inv;

    if(!this_object()->query("open"))
       return notify_fail("�Ův�L�o�O���w�g�ҰʤF�C\n");
    message_vision(HIW"$N�ҰʤF�Ův�L�o�˸m�ϤO��!!\n\n"NOR, this_player());
    this_object()->delete("open");

    inv = all_inventory(this_object());
    foreach(object user in inv)
    {
       if(!userp(user)) continue;
       if((user)->query("id") != "fedex")
       {
          message_vision(HIW"\n\n"HIY+user->query("name")+HIM",�ثe�o�Ӧa��L�k�i�J�C\n\n"NOR, user);
          user->move(__DIR__"workroom");
       }
    }
    return 1;
}
