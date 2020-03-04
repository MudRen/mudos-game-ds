#include <ansi.h>
inherit ITEM;

/*-------------�|�������ϰ�-------------*/
string *areas = ({
// "/open/world1/whoami/birdarea/",    //�F�_�A�L
   "/open/world1/acme/area/",          //�ѫ�
   "/open/world1/tmr/area/",           //�ɿ�
   "/open/world1/wu_sha_town/",        //�L����
   "/open/world1/cominging/purple_sun/"//�����s
});

void create()
{
    set_name(HIR"�w�ɬ��u"NOR,({ "bomb" }));
    if( clonep() )
    set_default_object(__FILE__);
    else
    {
       set("no_sell",1);
       set("no_drop",1);
       set("no_give",1);
       set("no_put",1);
       set("no_get",1);
       set("unit","��");
       set("value",0);
    }
    setup();
}

void init()
{
    add_action("do_throw", "throw");
}

/*-------------�P�O�i�H���Y���X�f-------------*/
int do_throw(string arg)
{
    object me = this_player();
    object ob = this_object();
    mapping exits = environment(me)->query("exits");

    if(!arg)
       return notify_fail("�A�n�����Ӥ�V���Y�H\n");
    if(sizeof(exits) < 1)
       return notify_fail("�o�̨S�����󪺥X�f�C\n");
    if(member_array(arg,keys(exits)) == -1)
       return notify_fail("�o�̨S��"+arg+"�o�ӥX�f�C\n");

    message_vision("$N��"+arg+"��X�F�@��$n�C\n",me,ob);
    tell_room(exits[arg],me->name(1)+"�³o�̥�F�@��"+ob->name()+"�C\n");

    ob->move(exits[arg]);
    call_out("follow",0);
    return 1;
}

/*-------------�P�w�H���z��-------------*/
int follow()
{
    object *list,ob,who;
    ob = this_object();
    list = all_inventory(environment(ob));
    who = list[random(sizeof(list))];

    // �]�w���L
    foreach(object user in list)
    {
       if(!userp(user) || !living(user)) continue;
       message_vision("$Nèè�����$n�C\n",ob,user);
       user->start_busy(3);
    }
    switch( random(10)+1)
    {
       case 1..9 :
            call_out("bamboo",3,list);
            break;
       default :
            message_vision(HIM"����Ƥ]�S���o��, �פڤF�äf��a\n"NOR,ob);
            destruct(ob);
            break;
    }
    return 1;
}

/*-------------�����Ҧ��H-------------*/
int bamboo(object *list)
{
    object ob;
    string *file,dir,room;
    ob = this_object();
    foreach(object user in list)
    {
        if(!living(user) || !userp(user)) continue;

        // ���o*areas���ɮצW��
        dir = areas[random(sizeof(areas))];
        file = get_dir(dir);
        room = dir + file[random(sizeof(file))];

        // ���������v
        switch( random(10)+1 )
        {
           case 1..9 :
                message_vision("\n\n\n\t["HIC" $N�� �� ���@�n�Q������"+room->query("short")+NOR" ]�C\n\n\n\n",user);
                tell_object(this_player(),user->name(1)+"�Q������ "+room->query("short")+"�C\n");
                user->move(room);
                break;
           default :
                message_vision(HIY"$N�F�����áA�k�L�F���u���i�ΡC\n"NOR,user);
                tell_object(this_player(),user->name(1)+"�F�����áA�k�L�F���u���i�ΡC\n");
                break;
        }
    }
    destruct(ob);
    return 1;
}
