inherit NPC;

void create()
{
        set_name("�q�u���Ĥl", ({"Worker's child","child"}) );
        set("long", "�o�W�Ĥl���b���˦a�W���p�g��A�L�y�պ��¡A�����f�H�A���O��}
�Q���j���A���ӬO�Y�W�q�u���Ĥl�C\n");
        set("race", "�H��");
        set("age", 5);
        set("level", 15);
        set("chat_chance", 10);
        set("chat_msg", ({
"�p�Ĥl�Τ����A����˦b�a�W���p�g��W...�C\n",
(: command("say ���Ӯ��Ҥl�ӧ�o�����㪺�d�g�ͤ@��...^^�C") :),
        }));

        setup();

}
int do_no_ask()
{
  write("�Х� say <��ͪ��覡> �Ө��o�һݱ����C\n");
  return 1;
}
