const SuperSqlite = require('./NativeSuperSqlite').default;

export function multiply(a: number, b: number): number {
  return SuperSqlite.multiply(a, b);
}
