
inherit NPC;
void create()
{
        set_name("�p��", ({ "dog" }));
        set("long","�@���g���⪺�p���C\n");

        set("race","���~");
        set("age",3);
        set("level",1);
        set("limbs", ({ "�Y�V","����","�զ�","�e�}","��}","��I" }) );
        set("verbs", ({ "bite", "claw","crash" }));

        set("chat_chance", 10);
        set("chat_msg",({
        (: command("dog"):),
        }));
        setup();
}
