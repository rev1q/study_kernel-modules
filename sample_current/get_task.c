/**
 * サンプルカーネルモジュール
 * - モジュール作成の勉強
 *
 * 概要
 * - CPUコア上で、現在実行されているスレッド（task_struct）を取得する
 *
 * Create Date : 2026/05/22
 *
 * Created By : Revi
 */

/**
 * 出力フォーマットの定義
 */
#define pr_fmt(fmt) "%s:%s(): " fmt, KBUILD_MODNAME, __func__

/**
 * ヘッダの定義
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Sample module using current");
MODULE_AUTHOR("Revi");

static int __init macro_init(void)
{
	pr_info("current : pid=%d , comm=%s\n", current->pid, current->comm);

	return 0;
}

static void __exit macro_exit(void)
{
	pr_info("finish output\n");
}

module_init(macro_init);
module_exit(macro_exit);
