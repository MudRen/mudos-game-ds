#include <ansi.h>
inherit ITEM;
void create()
{
         set_name(HIC"����"HIW"�p�N�U"HIM"�i"HIY + query("player_id") + HIM"�j"NOR, ({ "ingenious bag","bag" }) );
        set_weight(800);
        set_max_capacity(450);
        set_max_encumbrance(550000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�f");
                set("long", "�o�O�B�t��S�O�s�@���U�l�A�@�����|�h�A�����H�����U�M�~�����G\n"
                            "���ū᭫�s�_�X�A�̤����ԤW�ȯT����֡A�b�~���]�Ц��J�֦A�H��\n"
                            "�A�֭��]�q�A�W���٦��ȵ�¸�����ϮסA�U�f�A�Φ��b�a�Ϻ�A�U\n"
                            "���٦��S�O�Ϊ���¸�W���W�r�A���L���y���A�b�W�r�U���٬ݨ�F�@\n"
                            "�Ƥp�r�u�B�F��´�����B�t��s�@�v�C\n");
                set("value",8000);
               }
        set("player_id", "unknown");
        setup();
}

int query_unique() { return 1; }  // ���� daily eq


