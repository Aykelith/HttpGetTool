#include "JSONHighlighter.hpp"

JSONHighlighter::JSONHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("\".*\":");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    stringValuesFormat.setForeground(Qt::darkBlue);
    rule.pattern = QRegExp(": \".*\"");
    rule.format = stringValuesFormat;
    highlightingRules.append(rule);
}

void JSONHighlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
}
