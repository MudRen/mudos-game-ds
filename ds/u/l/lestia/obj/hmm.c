#define WALLITEM "��������"
#define WALLLONG "�@�ӥѤ��D�������X�Ӧ����j�O���ɡC\n"
#define WALLID   "lightwall"
inherit ITEM;
void create()
{
        set_name(WALLITEM,({WALLID}));
        set_weight(99999);
        set("long",WALLLONG);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "�h");
                set("value",0);
                set("no_drop",1);
                set("no_get",1);
                set("no_sac",1);
                }
        setup();
}
void init()
{
add_action("do_enter","enter");
add_action("do_go","go");
}

int do_enter(string arg)
{
     int invis;
object me;
me = this_player();
// if(!arg="enter") return notify_fail("���̥u���Ův�~��i�h�C\n");

me->move("/open/world1/acme/bonze/b19.c");
return 1;
}
int do_go(string arg)
{
int i;
object me = this_player();
if(arg="enter") return 0;
me->move("/open/world1/acme/bonze/b19.c");
return 1;
}
 
