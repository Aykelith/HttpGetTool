#ifndef JSONHIGHLIGHTER_HPP
#define JSONHIGHLIGHTER_HPP

#include <QSyntaxHighlighter>

class JSONHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    JSONHighlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;

private:
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QTextCharFormat quotationFormat;
    QTextCharFormat stringValuesFormat;
};

#endif // JSONHIGHLIGHTER_HPP
