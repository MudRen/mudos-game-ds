inherit ITEM ;
#include <ansi.h>

void create()
{
        set_name(HIC"�T���o�g��"NOR,({"massage item"}));
        set("unit","��");
        set("base_unit","��");
                set("value",5000);
set("long","�o�O�@�Ӽ����j�N�Ϥ����T���o�g���A�A�i�H�ΨӶǻ�(show)�����C\n");
        setup();
}

void init()
{
        add_action("do_show","show");
}

int do_show(string arg)
{
        object me = this_player();
        if( !arg || arg=="" ) return notify_fail("�A�n�g�Wԣ�r�S\n");
        message_vision(CYN"\n$N���_�F�Ϥ��A���V�Ѫ��I�_�P���C\n"NOR,me);
message_vision(HIR"\n�I�I�@�n�A�@���P���L�P�šC\n"NOR,me);
        tell_object(users(),
        HIC"\n\t�������ѻڡA��M���@�D�P�������a���L�{�{���P��..\n"NOR+
        HIY"\n\t��"NOR+YEL"��"HIR" ��"HIM"."NOR+MAG". "HIW+BLK"��"NOR"�@"HIW"�n"NOR"�A"HIW+BLK"�o"NOR"��"HIW"�P"NOR"�p"HIW+BLK"��"NOR"�}"HIW"��"NOR
"�A"HIW+BLK"�x"NOR"��"HIW"�F"NOR"�}"HIW+BLK"��"NOR"��"HIW"��"NOR".. \n"NOR+
        HIB"\n\t������ѪŧG"HIW"���F"NOR+RED"�y "HIY+arg+NOR+RED" �z"HIW"ģ��"HIB"����m�r..\n\n"NOR);
        destruct(this_object());
    return 1;
}

