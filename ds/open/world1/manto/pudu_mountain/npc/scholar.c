
inherit NPC;
void create()
{
        set_name("��H�̫�",({ "scholar"}));
        set("long","�Y�����y�A���۫C�m�A��n�鮰�A�n�Y�̸��u�֤�����H�C\n");
        set("level", 5);
        set("age",23);
        set("chat_chance", 8);
        set("chat_msg", ({
        (: command,"think �U�@�y�ӫ�򱵩O" :),
        (: command,"say �n�@�ӥj��M�դ���..." :),
        }) );
        setup();
        add_money("coin",100);
}
