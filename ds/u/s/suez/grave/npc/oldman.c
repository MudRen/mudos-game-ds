inherit NPC;
void create()
{
set_name("�ѤH",({"oldman"}));
set("long",@LONG

���S�e��A�y�a��a�A����@���s�A�p�u���g���A�K�ɰ��q�����աA
���ɧu�֥B�o�N�A�u�t�C�T���t�C�A�u�R��v�P��A�ȨӦ����H
�ȥh���ˤߡA�ӥh�����H���ơA�g�����H���Y�����v�A�h�~��P�h�A
���~�l�k�ڡC

LONG
);
     set("age",70);

     set("level", 77);
     set("chat_chance",7);
     set("gender","�k��");
     set("chat_msg",({
     "�ѤH�u��G�u�K�ݬ��СA��o�����h�ɪ��C�v\n",
     "�ѤH�u��G�u���ͥj���A�N�ۤ����C�C�C�v\n",
     "�ѤH��M�����j�����n�A���_�s��Ī�N�ܤF�@�j�f�C\n"
      }));
     set("attitude", "peaceful");
     set("talk_reply","�ӨӨӡI���ڳܪM�s�A���Ѥ��K���k�I");

     setup();
     add_money("coin", 1700);
}
