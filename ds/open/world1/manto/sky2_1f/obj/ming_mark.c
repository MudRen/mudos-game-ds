
#include <ansi.h>
#include <armor.h>
#define CLUB_NAME "����"
#define CLUB_ID "ming"

inherit FINGER;

void create()
{
        set_name(HIR"�t�w���w�O"NOR,({"Plate of Holy Fire","plate"}));
        set_weight(9999999);
        if( clonep() ) set_default_object(__FILE__);
        else
        {
                set("value",0);
                set("no_drop",1);
                set("no_sell",1);
                set("no_sac",1);
                set("no_get",1);
                set("no_give",1);
                set("unit","�u");
                set("long",@LONG
�o�O�κ��m��������O�P�A�W���z�۬����O�Ф���Ф��_
�ѩ_���K�H�һs�A�u�n�X�ܥO�P�A�j���n�_�Z��L���C

�b�e���L�ХD���u���~�p���`�����Z�A���O�P�N�d�b���B
�ѫ�H�����l��C
LONG
                );
        }
        set("club_id",CLUB_ID);
        set("club",CLUB_NAME);
        set("sub_club",({"���p��","��V��","�Ѽϰ�","�C���"}));
        set("armor_prop/shield", 1);
        setup();
}
