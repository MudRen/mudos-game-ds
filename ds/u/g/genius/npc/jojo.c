#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIB"���"NOR, ({"jojo"}) );
	set("long", "�@���|���ܪ��U�l\n");
	set("race", "�H��");
        set("evil",30);
        set("title",HIM"�]�H"NOR);
	set("age", 5);
	set("level", 100);

	setup();

}
int talk_action()
{
command("ccc");
command("say �ڬO�S���}�S�i�R�����!!");
command("say �w�w�̥i�R�{~~~~");
command("pat jojo");
return 1;
}
