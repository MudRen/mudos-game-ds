#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�F�Ʈv",({"secretary"}));
 set("long",@LONG
�L�O���񪺭ӤH�Ʈv, ���L��ڤW�޲z���ƪ�����]�t���h�F.
LONG
     );
 set("attitude","peaceful"); 
 set("age",24);
 set("gender","�k��");
 set("level",8);
 setup();
 carry_object(__DIR__"eq/sea_cloth")->wear();
 carry_object(__DIR__"eq/gold_fur_boots")->wear();
}
