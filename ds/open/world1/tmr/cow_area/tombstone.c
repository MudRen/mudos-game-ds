#include <ansi.h>
#include <path.h>

inherit ITEM;

#define COW_AREA_ENTER "/open/world1/tmr/cow_area/enter.c"

void create()
{
        set_name("�L���ѸO",({"meadow tombstone","tombstone"}) );
        set_weight(200000);
        set("long",@LONG
�o�O�@�y�ѹӸO�A�ΨӲ����Ҧ����b���L���W���ͪ��C�A�`�N��
�ӸO�W���ӷ�Ϊ��W���A�E�ݤ��U�A�٥H���O�֪��}�L�b�W���O�C
�A�γ\�|�Q�n�ոթ�m(place)����F��W�h�C
LONG
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","�y");
                set("no_get",1);
                set("no_sac",1);
                set("value", 20000);
        }
        setup();
}

void init()
{
        add_action("do_place", "place");
}

int do_place(string arg)
{
        object me, leg;
string item;
        me=this_player();
if(!arg || arg!="leg on tombstone")
return notify_fail("�A�Q�n��m(place)�����ӸO�W�H\n");
if( sscanf(arg, "%s on tombstone", item) != 1 )
return notify_fail("�A�Q�n��m(place)�����ӸO�W�H\n");

        if(!objectp(leg=present(item,me) ) )
                return notify_fail("�A���W�S���o�ӪF��C\n");
        
        if( leg->id("TRUMP_LEG") ) {
        message_vision(CYN "$N�N$n"CYN"�w�m��ӸO�W���W���A�Q����j�p��n�C\n" NOR, me, leg);
        message_vision(HIC "�@�}�{���X�{�A$N�b�ӸO�e���������F�C\n" NOR, me);
        me->move(COW_AREA_ENTER);
        destruct(leg);        
        } else {
        message_vision(CYN "$N�N$n"CYN"�w�m��ӸO�W���W���A�����볣�L�k��i�h�C\n" NOR, me, leg);
        }
        
        return 1;
}

