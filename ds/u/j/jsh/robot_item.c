inherit ITEM ;
#include <ansi.h>

void create()
{
        set_name(HIC"ROBOT�o�n��"NOR,({"robot item","item"}));
        set("unit","��");
        set("base_unit","��");
        set("needaward",1);  
        set("no_give",1);
        set("no_drop",1);
        set("no_sac",1);
set("long","Jangshow���M�ݰT���Ϋ~�C\n");
        setup();
}

void init()
{
        add_action("do_robotmsg","robotmsg");
}

int do_robotmsg(string arg)
{
        object me = this_player();
        if( !arg || arg=="" ) return notify_fail("�A�n�g����S\n");
        message_vision(CYN"\n$N�}�_ROBOT�o�n���A�V�̭����ۻy�C\n"NOR,me);
message_vision(HIR"\n�@�}���qROBOT�o�n����«�X�A���W�ѻڡI�C\n"NOR,me);
        tell_object(users(),
        HIR"\n\n\t�i���q�i�jJangshow�j�ۡG�y"+arg+"�z\n\n"NOR);
    return 1;
}
int query_autoload() { return 1; }


