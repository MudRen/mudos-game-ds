inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("�ר�����", ({ "repel-evil statue", "statue" }));
        set_weight(99999);
        if( !clonep() ) {
                set("unit", "��");
                set("no_get",1);
                set("container_unit", "�L");
                set("long",@long
�o�O�@�L�ά۫²r�������A��C���������G���@�۹L�����@���ƪ��A
���񪺤H���N��������m�b�o�A�N�O���F��ץ_��u��{��v���c����
�]���ǡC�o�����\��b�����G����ʦ~�����v�F�C
long
        );
        }
        setup();
}
void init()
{
        object me=this_player();
        if(me->id("_DULI_FIELD_NPC_") )
                me->force_me("go north");
}

