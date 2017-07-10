// Generated from Rose.g by ANTLR 4.5.3
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link RoseParser}.
 */
public interface RoseListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link RoseParser#token}.
	 * @param ctx the parse tree
	 */
	void enterToken(RoseParser.TokenContext ctx);
	/**
	 * Exit a parse tree produced by {@link RoseParser#token}.
	 * @param ctx the parse tree
	 */
	void exitToken(RoseParser.TokenContext ctx);
}